#include <ctime>
#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>
#include <chrono>

#include "gemmsg.pb.h"

using namespace std;
using namespace std::chrono;

using google::protobuf::util::TimeUtil;

// This function fills in a GemMsg message.
void PopulateMessage(trading::GemMsg* msg) {

    milliseconds ms;
    ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    long timestamp1 = ms.count();
    long timestamp2 = timestamp1 + 1;
    msg->set_id(timestamp1-1);
    msg->set_timestamp1(to_string(timestamp1));
    msg->set_timestamp2(to_string(timestamp2));

    *msg->mutable_last_updated() = TimeUtil::SecondsToTimestamp(time(NULL));
}

// Iterates though all messages in the GemMsgList and prints info about them.
void ListMessages(const trading::GemMsgList& message_list) {
    for (int i = 0; i < message_list.messages_size(); i++) {
        const trading::GemMsg& msg = message_list.messages(i);

        cout << "           ID: " << msg.id() << endl;
        cout << "   Timestamp1: " << msg.timestamp1() << endl;
        cout << "   Timestamp2: " << msg.timestamp2() << endl;

        if (msg.has_last_updated()) {
            cout << "Updated: " << TimeUtil::ToString(msg.last_updated()) << endl;
        }
    }
}

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    trading::GemMsgList message_list;

    string filename = "./MyMessages";
    cout << "Filename: " << filename << "\n\n";

    {
        // Read the existing message list.
        fstream input(filename, ios::in | ios::binary);
        if (!input) {
            cout << filename << ": File not found.  Creating a new file." << endl;
        } else if (!message_list.ParseFromIstream(&input)) {
            cerr << "Failed to parse message list." << endl;
            return -1;
        }
    }

    // Display existing messages.
    ListMessages(message_list);

    cout << "\n";

    // Add a message.
    PopulateMessage(message_list.add_messages());

    {
        // Write the new message list back to disk.
        fstream output(filename, ios::out | ios::trunc | ios::binary);
        if (!message_list.SerializeToOstream(&output)) {
            cerr << "Failed to write message list." << endl;
            return -1;
        }
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
