import socket 

server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(("0.0.0.0",8080))
server_socket.listen(1)

print("Server is Listening on Port 8080...")

conn, addr = server_socket.accept()
print(f"Connection from {addr}")

data = conn.recv(1024).decode()
print(f"Recived: {data}")

conn.send("Hello from the server!".encode())

conn.close()
server_socket.close()
