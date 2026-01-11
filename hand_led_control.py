import cv2
import mediapipe as mp
import requests

# --------- Configuration ----------
ESP_IP = "192.168.31.234"  # Replace with your ESP8266 IP
ESP_URL = f"http://192.168.31.234/"

# --------- MediaPipe Setup ----------
from mediapipe.python.solutions import hands as mp_hands
from mediapipe.python.solutions import drawing_utils as mp_draw

hands = mp_hands.Hands(max_num_hands=1, min_detection_confidence=0.7, min_tracking_confidence=0.7)

FINGER_TIPS = [8, 12, 16, 20]
THUMB_TIP = 4

cap = cv2.VideoCapture(0)

# --------- Helper Functions ----------
def send_command(command):
    try:
        requests.get(f"{ESP_URL}{command}", timeout=0.5)
    except:
        pass  # Ignore network errors

def control_leds(finger_count):
    if finger_count == 0:
        send_command("ALL_OFF")
    elif finger_count == 1:
        send_command("L1_ON")
    elif finger_count == 2:
        send_command("L2_ON")
    elif finger_count == 3:
        send_command("L3_ON")
    elif finger_count == 5:
        send_command("ALL_ON")

# --------- Main Loop ----------
while True:
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.flip(frame, 1)
    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    result = hands.process(rgb)

    finger_count = 0

    if result.multi_hand_landmarks:
        hand_landmarks = result.multi_hand_landmarks[0]
        lm = hand_landmarks.landmark

        # Thumb (horizontal)
        if lm[THUMB_TIP].x < lm[THUMB_TIP - 1].x:
            finger_count += 1

        # Other fingers (vertical)
        for tip in FINGER_TIPS:
            if lm[tip].y < lm[tip - 2].y:
                finger_count += 1

        mp_draw.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

    # Display
    cv2.putText(frame, f"Fingers: {finger_count}", (20,50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2)
    cv2.imshow("Hand LED Control", frame)

    # Send commands to ESP
    control_leds(finger_count)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
