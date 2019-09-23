#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>

#include "gemmsg.pb.h"

using namespace std;

using google::protobuf::util::TimeUtil;

/*
To create the required files, we run the protocol buffer compiler,
specifying the source directory (where your applications's source code
lives - the current directory is used if you don't provide a value), the
destination directory (where you want the generated code to go; often the
same as $SRC_DIR), and the path to your .proto. In this case, you...

protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/addressbook.proto

Because you want C++ classes, you use the --cpp_out option - similar
options are provided for other supported languages.

This generates the following files in your specified destination directory:
- addressbook.pb.h, the header which declares your generated classes.
- addressbook.pb.cc, which contains the implementation of your classes.
*//*
To compile a package that uses Protocol Buffers, you need to pass
various flags to your compiler and linker. If you have pkg-config
installed, then you can invoke it to get a list of flags like so:

    pkg-config --cflags protobuf         # print compiler flags
    pkg-config --libs protobuf           # print linker flags
    pkg-config --cflags --libs protobuf  # print both

For example:

    c++ my_program.cc my_proto.pb.cc `pkg-config --cflags --libs protobuf`
*//*
To compile:

    g++ -std=c++17 addressbook.cc addressbook.pb.cc `pkg-config --cflags --libs protobuf`
*/


// Iterates though all GemMsg messages in the GemMsgList and prints info about them.
void ListMessages(const trading::GemMsgList& message_list) {
  for (int i = 0; i < message_list.people_size(); i++) {
    const trading::GemMsg& msg = message_list.messages(i);

    cout << "          ID: " << msg.id() << endl;
    cout << "  Timestamp1: " << msg.timestamp1() << endl;
    cout << "  Timestamp2: " << msg.timestamp2() << endl;
    /*if (person.email() != "") {
      cout << "  E-mail address: " << person.email() << endl;
    }*/

    /*for (int j = 0; j < msg.xxxxes_size(); j++) {
      const trading::GemMsg::PhoneNumber& phone_number = person.phones(j);

      switch (phone_number.type()) {
        case tutorial::Person::MOBILE:
          cout << "  Mobile phone #: ";
          break;
        case tutorial::Person::HOME:
          cout << "  Home phone #: ";
          break;
        case tutorial::Person::WORK:
          cout << "  Work phone #: ";
          break;
        default:
          cout << "  Unknown phone #: ";
          break;
      }
      cout << phone_number.number() << endl;
    }*/
    if (msg.has_last_updated()) {
      cout << "     Updated: " << TimeUtil::ToString(msg.last_updated()) << endl;
    }
  }
}


int main()
{
    cout << "gemmsg_test.cc program to test protobuf messaging" << "\n\n";

    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    trading::GemMsgList message_list;
    
    string filename = "./MyGemMessages";

    cout << "Filename: '" << filename << "'\n\n";

    {
        // Read the existing message list.
        fstream input(filename, ios::in | ios::binary);
        if (!address_book.ParseFromIstream(&input)) {
            cerr << "Failed to parse message list." << endl;
            return -1;
        }
    }

    ListMessages(message_list);

    cout << "\n";

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();


    /*tutorial::Person person;
    person.set_name("John Doe");
    person.set_id(1234);
    person.set_email("jdoe@example.com");
    std::fstream output("./myfile", std::ios::out | std::ios::binary);
    person.SerializeToOstream(&output);

    // ... do other stuff ...

    std::fstream input("./myfile", std::ios::in | std::ios::binary);
    tutorial::Person p2;
    p2.ParseFromIstream(&input);
    std::cout << "Name: " << p2.name() << std::endl;
    std::cout << "E-mail: " << p2.email() << std::endl;*/

    return 0;
}