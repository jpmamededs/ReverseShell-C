Description

This project is a reverse shell malware written in C, developed as part of studies in networks and cybersecurity. It allows an attacker to gain remote control of a machine and execute commands on the victim’s terminal.

How It Works
	1.	The attacker starts a listener on the server to wait for connections.
	2.	The victim executes the malware, which:
	•	Establishes a connection to the server.
	•	Redirects the victim’s terminal (cmd.exe) to the created socket.
	3.	The attacker then gains full remote control of the victim’s machine.

Requirements

1. Development Environment
	•	Operating System: Windows
	•	Compiler: GCC (MinGW for Windows)
	•	Winsock2 library included (default in Windows).

2. Tools Needed on the Server
	•	Netcat (or alternatives like Socat) to create the listener.

Step-by-Step Instructions

1. For the attacker, launch the 'server' compiled code.

  1.2.	Netcat will now wait for incoming connections from the malware.

2. Execute the Malware on the Victim’s Machine
	2.1.	Transfer the shell.exe to the target machine.
	2.2.	When the executable is run on the victim’s machine, it will attempt to connect to the attacker’s server using the specified IP and port.

3. Control the Victim’s Machine
	3.1.	Once the connection is established, you will gain access to the victim’s terminal through Netcat.
	3.2.	You can now execute commands remotely.

Future Improvements
	•	Add encryption to the data transfer for stealthier connections.
	•	Implement cross-platform compatibility.
	•	Explore methods to bypass firewalls and antivirus detection.
