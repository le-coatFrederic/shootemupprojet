bindir = bin/
servername = $(bindir)server
clientname = $(bindir)client
cxx = g++
cxxflags = -lsfml-network -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
server_src = $(wildcard src/server/*.cpp src/server/*/*.cpp src/server/*/*/*.cpp src/server/*/*/*/*.cpp)
server_head = $(wildcard src/server/*.hpp src/server/*/*.hpp src/server/*/*/*.hpp src/server/*/*/*/*.hpp)
server_objs = $(addprefix obj/server/, $(notdir $(patsubst src/server/%.cpp, obj/server/%.o, $(server_src))))
client_src = $(wildcard src/client/*.cpp src/client/*/*.cpp src/client/*/*/*.cpp src/client/*/*/*/*.cpp)  
client_head = $(wildcard src/client/*.hpp src/client/*/*.hpp src/client/*/*/*.hpp src/client/*/*/*/*.hpp)
client_objs = $(addprefix obj/client/, $(notdir $(patsubst src/client/%.cpp, obj/client/%.o, $(client_src))))

all: $(servername) $(clientname)

$(servername): $(server_src) $(server_head)
	$(cxx) -o $@ $^ $(cxxflags)

$(clientname): $(client_src) $(client_head)
	$(cxx) -o $@ $^ $(cxxflags)

affichage: $(server_src) $(server_head) $(client_src) $(client_head) $(server_objs) $(client_objs)
	echo -e "\n$(server_src)\n$(server_head)\n$(client_src)\n$(client_head)\n\n$(server_objs)\n$(client_objs)"

git : gitserver gitclient
	git add makefile

gitserver: $(server_src) $(server_head)
	git add $^

gitclient: $(client_src) $(client_head)
	git add $^