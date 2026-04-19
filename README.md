# The Witch

This project explores how light can create simple but expressive movement in a physical computing piece. A witch cat character is placed inside a layered paper environment, where motion is controlled by light sensors and servo motors.

The arms move slowly as an idle behavior, making the character feel alive even without interaction. When someone moves their hand near the sensor and blocks the light, it triggers the circular elements behind the character to rotate, creating a stronger visual response.
<img width="1280" height="720" alt="Nia-The-Witch-Thumbnail" src="https://github.com/user-attachments/assets/12d66641-a62d-4aaa-8c1c-58dc71f08a0e" />

---

## Concept

The idea is to create a witch-like character that feels charming and alive. The slow arm movement, even in bright light, gives a lively feeling. When someone interacts with it, the piece reacts more strongly, as if the character is casting a spell and pulling the viewer into its world.

---

## Circuit Setup

- Light Sensor 1 → A0 (controls circular movement)  
- Light Sensor 2 → A1 (controls arm movement)  

- Continuous Rotation Servo → Pin 9 (circles behind the character)  
- 180° Servo → Pin 10 (arm movement)  

- All components share a common GND  
- Light sensors use 10kΩ resistors (voltage divider)  
- Powered by USB power bank  

---

## Materials & Components

**Materials:**
- Thick paper / cardstock  
- Wooden box  
- Black acrylic paint (Liquitex)  
- Aluminum wire  
- 3D foam tape  

**Electronics:**
- Arduino UNO R4 WiFi  
- Mini breadboard  
- Continuous rotation servo  
- 180-degree servo  
- Light sensors (photoresistors)  
- 10kΩ resistors  
- Jumper wires  
- Power bank  

---

## Process

1. Organized wiring on a mini breadboard and tested sensors and servos  
2. Soldered connections for stability  
3. Drilled hole and painted box black  
4. Created paper layers using a cutting knife  
5. Built internal base and hid wiring  
6. Created arm mechanism using aluminum wire  
7. Installed moving structure connected to servo  
8. Added decorative layers to build the scene  
9. Finished outer paper frame  

---

## Notes

- A knife was used instead of scissors for tight curved details  
- 3D foam tape was used to create depth and shadow  
- The system responds to changes in light rather than fixed values  
