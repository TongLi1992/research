#include <iostream>
#include <fstream>
#include <string>
#include "image.pb.h"
using namespace std;



// Main function:  Reads the entire address book from a file and prints all
//   the information inside.
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 3) {
    cerr << "Usage:  " << argv[0] << " image_encoded_file  out_put_image_file" << endl;
    return -1;
  }

  tutorial::Image image;

  {
    // Read the existing address book.
    fstream input(argv[1], ios::in | ios::binary);
    if(input.is_open()) {
      if (!image.ParseFromIstream(&input)) {
      cerr << "Failed to parse image." << endl;
      return -1;
      }
    } else {
      cout<<"open "<<argv[1]<<" failed";
      return -1;
    }
    
  }

  string *temp = image.mutable_contents();
  cout<<image.name()<<endl;
  ofstream fout;
  fout.open(argv[2]);
  fout<<*temp;
  fout.close();
  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}