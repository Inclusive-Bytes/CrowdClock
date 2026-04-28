

# CrowdClock

**Self-synchronising LED badges using ESP-NOW**

> A distributed system where devices don’t sync animations — they sync time.

---

## 🎥 Demo

See the badges in action:
👉 [https://youtu.be/YINVdLlnf9U(https://youtu.be/YINVdLlnf9U)

Badges automatically synchronise their lighting effects when they come close together.

* No pairing
* No configuration
* No central controller

They just… sync.

---

## 🧠 How It Works

Each badge broadcasts its local clock using ESP-NOW.
Instead of sending raw time, the value is **quantised into 50 ms steps**:

```cpp
tick = millis() - (millis() % 50);
```

When a badge receives a time value greater than its own, it adopts it:

```cpp
time = max(time_seen);
```

This creates a simple, emergent synchronisation mechanism:

* No master node
* No topology
* No device tracking

---

## 🔄 From Time to Light

All badges run the same code and derive their behaviour from time:

```
tick → effect index → effect state → LED output
```

* **Effect selection** is based on time
* **Effect state** is based on time

Once clocks align, everything else follows automatically.

---

## ⚙️ Why It Works

### 🔹 Quantised Time

Rounding time to 50 ms:

* Absorbs network latency
* Prevents oscillation
* Ensures stable convergence

### 🔹 Fast Broadcast

* ESP-NOW transmission every ~5 ms
* Multiple opportunities for propagation

### 🔹 Perceptual Design

Effects are:

* Flashes
* Chases
* Discrete patterns

This avoids visible artefacts from small timing differences.

---

## 🧩 Hardware

Each badge includes:

* ESP32-C3 Mini
* WS2812 LED ring
* 1Ah LiPo battery
* Boost/BMS module (5V output)

PCBs were CNC routed and assembled in workshops.

---

## 🔧 A Note on ESP32 Mounting

Early versions used socketed ESP32 modules.
This caused unreliable ESP-NOW reception.

Removing the sockets and soldering the modules directly resolved the issue.

At 2.4 GHz, small physical details matter.

---

## 👩‍🔧 Built with Inclusive Bytes

This project was developed with participants at
Inclusive Bytes

* Community workshops
* Soldering and assembly
* Custom lighting effects written by students

The system itself mirrors the process:

> many independent parts working together to create something unified.

---

## 🎉 In the Wild

The badges were created for the Oldham Illuminate Festival.

* Small groups synchronise
* Groups merge and re-align
* The crowd becomes part of the system

---

## 🚀 Future Ideas

* Visualising time propagation
* Multiple competing “time groups”
* Alternative effect systems
* Binary packet format (non-JSON)

---

## 📦 Repository Structure

https://github.com/Inclusive-Bytes/CrowdClock

```
/src            → firmware  
/include 		→ header files
/hardware       → PCB and design files  

```

---

## 📜 Licence

This project is released under a Creative Commons licence  CC BY-NC 4.0

You are free to:

* Share
* Adapt
* Build upon

Please provide appropriate credit.


---

## 💡 Key Idea

> Synchronise time, not state.

---

## 🙌 Acknowledgements

Thanks to everyone at Inclusive Bytes who helped build, test, and extend the badges.

---

