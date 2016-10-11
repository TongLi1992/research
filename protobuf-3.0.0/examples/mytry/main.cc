#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
using namespace std;

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
    return -1;
  }

  tutorial::Image image;

  
	// Read the existing address book.
	fstream input(argv[1], ios::in | ios::binary);
	if (!input) {
	  cout << argv[1] << ": File not found.  Creating a new file." << endl;
	}
  streamsize size = input.tellg();
  file.seekg(0, std::ios::beg);
  char *buffer = new char[size];
  image.set_contents(buffer);

  {
    // Write the new address book back to disk.
    fstream output("pic1", ios::out | ios::trunc | ios::binary);
    if (!image.SerializeToOstream(&output)) {
      cerr << "Failed to write address book." << endl;
      return -1;
    }
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}