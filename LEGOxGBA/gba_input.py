import RPi.GPIO as GPIO
import uinput
import time

# Define GPIO BCM code
# Should be related to your own GPIO wires
btnLeft = 24
btnRight = 23
btnUp = 25
btnDown = 18

btnA = 26
btnB = 21
btnL = 22
btnR = 20

btnStart = 17
btnSelect = 27

# Button callback, param channel is BCM code defined above
# GPIO state 'Low' means button pressed because my wires are PUD_UP mode
def button_trigger(channel):
    state = not GPIO.input(channel)

    if channel == btnLeft:
        device.emit(uinput.BTN_DPAD_LEFT, state)
    elif channel == btnRight:
        device.emit(uinput.BTN_DPAD_RIGHT, state)
    elif channel == btnUp:
        device.emit(uinput.BTN_DPAD_UP, state)
    elif channel == btnDown:
        device.emit(uinput.BTN_DPAD_DOWN, state)
    elif channel == btnA:
        device.emit(uinput.BTN_A, state)
    elif channel == btnB:
        device.emit(uinput.BTN_B, state)
    elif channel == btnL:
        device.emit(uinput.BTN_TL, state)
    elif channel == btnR:
        device.emit(uinput.BTN_TR, state)
    elif channel == btnStart:
        device.emit(uinput.BTN_START, state)
    elif channel == btnSelect:
        device.emit(uinput.BTN_SELECT, state)
    # See print out to check your wires
    if state == 1:
        print("Pressed:{:>2}".format(channel))
    else:
        print("Release:{:>2}".format(channel))

# Set mode
GPIO.setmode(GPIO.BCM)
# Disable warnings
# GPIO.setwarnings(False)
# Init GPIO, PUD_UP means 'High' defaut, should input 'Low'
GPIO.setup(btnLeft, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnRight, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnUp, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnDown, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnA, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnB, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnL, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnR, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnStart, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(btnSelect, GPIO.IN, pull_up_down=GPIO.PUD_UP)

# Add call back
GPIO.add_event_detect(btnLeft, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnRight, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnUp, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnDown, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnA, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnB, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnL, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnR, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnStart, GPIO.BOTH, callback=button_trigger)
GPIO.add_event_detect(btnSelect, GPIO.BOTH, callback=button_trigger)

# uinput init
# Simply use BTN_0 ~ BTN_9 maybe OK, because button's
# real function only depends on input configs of RetroPie
events = (
    uinput.BTN_A,
    uinput.BTN_B,
    uinput.BTN_TL,
    uinput.BTN_TR,
    uinput.BTN_START,
    uinput.BTN_SELECT,
    uinput.BTN_DPAD_LEFT,
    uinput.BTN_DPAD_RIGHT,
    uinput.BTN_DPAD_UP,
    uinput.BTN_DPAD_DOWN,
    )

# Open uinput device
with uinput.Device(events) as device:
    print("GBA_INPUT DEVICE STARTED!")
    while True:
        # Dont know if this sleep is needed
        time.sleep(0.01)
    
