

🧩 What Is a Socket?

A socket is like a doorway or telephone jack that lets your server talk to the outside world (like browsers, curl, etc.) over the network.

Think of it like this:

🧑‍🍳 You (the server) are in the kitchen.
📞 The socket is your phone line.
🧑‍💻 A client (like a browser) calls you over the socket to ask for a dish (file or page).
📦 You pick up the phone, take the order, prepare the response, and send it back.

⸻

🔧 What Sockets Do in a Web Server
	1.	Create a socket — “plug in the phone.”
	2.	Bind it to an IP address and port — “set your number.”
	3.	Listen on it — “wait for calls.”
	4.	Accept connections — “pick up the phone.”
	5.	Read from it — get client request.
	6.	Write to it — send HTTP response.
	7.	Close it — hang up.

⸻

🛠️ C++ System Calls Used

These are system-level functions you’ll use:

Function	Purpose
socket()	Create a socket
bind()	Bind it to an IP and port
listen()	Make it listen for incoming connections
accept()	Accept a connection from a client
read() / recv()	Read data from client
write() / send()	Send data back
close()	Close the connection



⸻

📚 Types of Sockets

In your webserv, you’re using:
	•	AF_INET → IPv4 (e.g. 127.0.0.1)
	•	SOCK_STREAM → TCP (connection-based, like HTTP)

int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

This says: “Create a TCP socket that uses IPv4.”

⸻

📥 Real Example Flow in Webserv

// 1. Create socket
int server_fd = socket(AF_INET, SOCK_STREAM, 0);

// 2. Bind to port 8080
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(8080);
addr.sin_addr.s_addr = INADDR_ANY;
bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));

// 3. Listen for connections
listen(server_fd, SOMAXCONN);

// 4. Accept a client
int client_fd = accept(server_fd, NULL, NULL);

// 5. Communicate
read(client_fd, buffer, BUFSIZE);
write(client_fd, response, strlen(response));

// 6. Close connections
close(client_fd);
close(server_fd);



⸻

🧠 Summary

Term	Analogy	Purpose
socket	Telephone jack	Create a communication channel
bind	Get a phone number	Attach to IP and port
listen	Wait for calls	Wait for clients to connect
accept	Pick up the call	Establish connection with client
read	Hear request	Receive HTTP request
write	Speak response	Send back HTTP response
close	Hang up	End connection

