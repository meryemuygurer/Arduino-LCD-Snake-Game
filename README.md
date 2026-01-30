# Arduino LCD Snake Game

This project is a simple Snake game implemented on Arduino Uno using a 16x2 LCD, an analog joystick, a potentiometer, and a buzzer. The main objective is to demonstrate both hardware and software skills in Arduino programming and electronic circuit design. This project was developed as part of a course project for project management and STEM learning purposes.

---

## 🎯 Project Objective

The aim of this project is to:

- Design and implement a simple Snake game on Arduino.  
- Learn how to integrate hardware components like LCD displays, joysticks, buzzers, and potentiometers.  
- Develop problem-solving and programming skills in an embedded systems environment.  
- Demonstrate a STEM-based approach combining Science, Technology, Engineering, and Mathematics concepts.

---

## 🧩 Components Used

- **Arduino Uno** – microcontroller board  
- **16x2 LCD Display** – to display the game interface  
- **Analog Joystick Module** – to control the snake  
- **Potentiometer** – to adjust LCD contrast  
- **Buzzer** – for audio feedback when the snake hits obstacles  
- **Breadboard, resistors, jumper wires** – to connect components

---

## ⚙️ Hardware Setup

> LCD connections:

- RS → 7  
- E → 6  
- D4 → 5  
- D5 → 4  
- D6 → 3  
- D7 → 2  

**Joystick connections:**

- VRX → A0  
- VRY → A1  
- SW → 9  
- VCC → 5V  
- GND → GND  

**Potentiometer connections:**

- CW → 5V  
- CCW → GND  
- Wiper → LCD VO (contrast)

**Buzzer connection:**

- Digital pin 10 → Buzzer positive  
- GND → Buzzer negative

---

## 🕹 Game Rules

- Use the joystick to control the snake’s movement.  
- Eating `*` increases your score.  
- Hitting `#` decreases your life/score; game resets when all lives are lost.  
- Score of 6 `*` symbols → win the game.  
- The buzzer sounds when hitting obstacles.

---

## 📁 Project Structure
```
Arduino-LCD-Snake-Game/
├── src/ # Arduino sketch files (.ino)
├── docs/ # Project report, screenshot of the Wokwi circuit
├── videos/ # .txt files with YouTube links to demo and gameplay
├── README.md # This file
└── LICENSE # MIT License
```
---

## 🎥 Project Videos

- **Circuit Demo Video:** [YouTube Link](https://www.youtube.com/watch?v=vwsQqGvnxbQ&feature=youtu.be)
- **Gameplay Demo Video:** [YouTube Link]https://youtu.be/XF8yxkFeSwc)

*(Videos are uploaded as unlisted on YouTube. Links are stored in .txt files inside the `videos/` folder.)*

---

## 💡 Future Improvements

- Add levels with increasing speed or additional obstacles.  
- Add LED or sound feedback for eating food.  
- Implement mobile or web-based control using Bluetooth or Wi-Fi.  
- Use a larger screen (TFT) for better graphics.  
- Enable multiplayer mode with two joysticks.

---

## 📚 STEM Learning Outcomes

- Understanding the operation of electronic components.  
- Practicing Arduino programming skills.  
- Developing problem-solving and project management experience.  
- Applying theoretical STEM knowledge in a practical project environment.

---

## 🔗 GitHub Repository

[Arduino LCD Snake Game Repository](https://github.com/meryemuygurer/Arduino-LCD-Snake-Game)
