# Uses protobuf: addressbook.proto
# Build for C++ and/or Python (add_person, list_people, addressbook)

.PHONY: all cpp python clean

all: cpp python

#cpp:    add_person_cpp    list_people_cpp		addressbook_cpp
cpp:	gemmsg_cpp 			gemmsg_add_cpp
python: add_person_python 	list_people_python

clean:
	rm -f add_person_cpp list_people_cpp add_person_python list_people_python
	rm -f protoc_middleman addressbook.pb.cc addressbook.pb.h addressbook_pb2.py
	rm -f *.pyc
	#rmdir tutorial 2>/dev/null || true
	#rmdir com/example/tutorial 2>/dev/null || true
	#rmdir com/example 2>/dev/null || true
	#rmdir com 2>/dev/null || true

protoc_middleman: addressbook.proto
	protoc $$PROTO_PATH --cpp_out=. --python_out=. addressbook.proto
	@touch protoc_middleman

gemmsg_add_cpp: gemmsg_add.cc protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	g++ -std=c++17 gemmsg_add.cc gemmsg.pb.cc -o gemmsg_add_cpp `pkg-config --cflags --libs protobuf`

gemmsg_cpp: gemmsg_test.cc protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	g++ -std=c++17 gemmsg_test.cc gemmsg.pb.cc -o gemmsg_cpp `pkg-config --cflags --libs protobuf`

add_person_cpp: add_person.cc protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	g++ -std=c++17 add_person.cc addressbook.pb.cc -o add_person_cpp `pkg-config --cflags --libs protobuf`

list_people_cpp: list_people.cc protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	g++ -std=c++17 list_people.cc addressbook.pb.cc -o list_people_cpp `pkg-config --cflags --libs protobuf`

addressbook_cpp: addressbook.cc protoc_middleman
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	g++ -std=c++17 addressbook.cc addressbook.pb.cc -o addressbook_cpp `pkg-config --cflags --libs protobuf`

add_person_python: add_person.py protoc_middleman
	@echo "Writing shortcut script add_person_python..."
	@echo '#! /bin/sh' > add_person_python
	@echo './add_person.py "$$@"' >> add_person_python
	@chmod +x add_person_python

list_people_python: list_people.py protoc_middleman
	@echo "Writing shortcut script list_people_python..."
	@echo '#! /bin/sh' > list_people_python
	@echo './list_people.py "$$@"' >> list_people_python
	@chmod +x list_people_python
