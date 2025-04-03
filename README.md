# Reverse Shell Malware

This project is a **reverse shell malware** written in **C**, developed as part of my studies in networks and cybersecurity. It allows an attacker to gain **remote control** of a machine and run commands on the victim’s terminal.

---

<details>
  <summary>✅ Updates:</summary>
<br>
   
**(04/01/2025)** - Now it bypasses Windows Defender.

</details>

---

<details>
  <summary> <strong> How It Works? </strong> </summary>
<br>
   
1. **The attacker starts a listener** on the server to wait for connections. <br>
2. **The victim executes the malware**, which:
   - Establishes a connection to the server.
   - Redirects the victim’s terminal (`cmd.exe`) to the created socket. <br>
3. **The attacker gains full remote control** of the victim’s machine.

</details>

---

<details>
  <summary> <strong> Requirements </strong> </summary>
<br>

  ### As an **Attacker**:
   
- **Netcat** (or alternatives like Socat) to create the listener.
- **Linux**

</details>

---

## 🚨‼️ THIS WAS MADE FOR EDUCATIONAL PURPOSES

---

## 📋 Step-by-Step Instructions

### 1. Set Up the Listener on the Attacker's Server
1.1. Go to the directory you downloaded `server` and run the command in a terminal: `./server`

1.2. Wait for incoming connections from the malware.

### 2. Open `reverseShell.c` in a code editor and change `ipAddress's` value to the attacker's IP, then save.

  2.1. In the same directory, run this command in the terminal: `gcc -o shell.exe reverseShell.c -lws2_32 -mwindows`
  <br>
  **Extra:** To change the executable's name, change 'shell.exe' to 'your desireable name' + .exe

#### 2.2. Run the Executable
- Execute the `shell.exe` file on the victim’s machine.  
- Once executed, the malware will:
  - Attempt to connect to the attacker’s server using the predefined **IP address** and **port**.
  - Establish a reverse shell session, providing remote access to the victim’s terminal.

### 3. Gain Control of the Victim's Machine

#### 3.1. Establish the Connection
- Once the victim executes the malware, a **reverse shell** connection will be established.  
- You can now access the victim’s terminal through **Netcat**.

#### 3.2. Execute Remote Commands
- Use the terminal session to remotely execute commands on the victim’s machine.  
- Example commands you can run:
  - **File exploration**: `dir` (Windows) or `ls` (Linux)
  - **Download files**: Use `curl` or `wget` if available.
  - **System monitoring**: `tasklist` (Windows) or `top` (Linux)
 
## 🔮 Future Improvements

### 1. Add Encryption
- Implement **encryption protocols** (e.g., AES or RSA) to secure data transfer between the attacker and the victim.
- Ensure stealthier connections by making traffic less detectable by network monitoring tools.

### 2. Cross-Platform Compatibility
- Extend support for other operating systems such as:
  - **Linux**
  - **macOS**
- Refactor the codebase to use platform-independent libraries for socket communication.

### 3. Firewall/Antivirus Evasion
- Develop advanced methods to bypass:
  - **Firewalls**: Use techniques like packet fragmentation or tunneling.
  - **Antivirus Detection**: Implement techniques such as obfuscation, polymorphic code, or process injection.

---

https://github.com/user-attachments/assets/744289bf-0009-4d35-9af4-35dea01edebc

---

# 🚨 That's only a code demonstration of the Malware, I'm not responsible for any misuse of the code and the malware.
