/*#include <iostream>
#include <fstream>
#include "addressbook.pb.h"*/

#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>

#include "addressbook3.pb.h"

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
*/


/*
To compile a package that uses Protocol Buffers, you need to pass
various flags to your compiler and linker. If you have pkg-config
installed, then you can invoke it to get a list of flags like so:

    pkg-config --cflags protobuf         # print compiler flags
    pkg-config --libs protobuf           # print linker flags
    pkg-config --cflags --libs protobuf  # print both

For example:

    c++ my_program.cc my_proto.pb.cc `pkg-config --cflags --libs protobuf`
*/

/*
To compile:

    g++ -std=c++17 addressbook.cc addressbook.pb.cc `pkg-config --cflags --libs protobuf`
*/


// Iterates though all people in the AddressBook and prints info about them.
void ListPeople(const tutorial::AddressBook& address_book) {
  for (int i = 0; i < address_book.people_size(); i++) {
    const tutorial::Person& person = address_book.people(i);

    cout << "Person ID: " << person.id() << endl;
    cout << "  Name: " << person.name() << endl;
    if (person.email() != "") {
      cout << "  E-mail address: " << person.email() << endl;
    }

    for (int j = 0; j < person.phones_size(); j++) {
      const tutorial::Person::PhoneNumber& phone_number = person.phones(j);

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
    }
    if (person.has_last_updated()) {
      cout << "  Updated: " << TimeUtil::ToString(person.last_updated()) << endl;
    }
  }
}


int main()
{
    cout << "addressbook.cc program to test protobuf" << "\n\n";

    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    tutorial::AddressBook address_book;
    
    string filename = "./MyAddressBook";

    cout << "Filename: '" << filename << "'\n\n";

    {
        // Read the existing address book.
        fstream input(filename, ios::in | ios::binary);
        if (!address_book.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
    }

    ListPeople(address_book);

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