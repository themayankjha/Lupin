

server_objects = ServerSocket.o Socket.o server.o
player_one_objects = ClientSocket.o Socket.o player_one.o
player_two_objects = ClientSocket.o Socket.o player_two.o



all : server player_one player_two

server: $(server_objects)
	g++ -o server $(server_objects)


player_one: $(player_one_objects)
	g++ -o player_one $(player_one_objects) -lGL -lglut -lGLU -lm

player_two: $(player_two_objects)
	g++ -o player_two $(player_two_objects) -lGL -lglut -lGLU -lm


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
server: server.cpp
player_one: player_one.cpp
player_two: player_two.cpp


clean:
	rm -f *.o server player_one player_two