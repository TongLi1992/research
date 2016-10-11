#include <iostream>
#include <fstream>
#include <string>
#include "image.pb.h"
using namespace std;

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  cout<<1<<endl;
  if (argc != 4) {
    cerr << "Usage:  " << argv[0] << " image_file  output_encoded_file image_name" << endl;
    return -1;
  }
  cout<<2<<endl;
  tutorial::Image image;

  
	// Read the existing address book.
	fstream input(argv[1], ios::in | ios::binary);
  // ifstream input(argv[1]);
	cout<<3<<endl;
  if (!input) {
	  cout << argv[1] << ": File not found.  Creating a new file." << endl;
	}
  input.seekg (0, input.end);
  int size = input.tellg();
  cout<<"size is "<<size<<endl;
  input.seekg (0, input.beg);
  char *buffer = new char[size];
  if(buffer == 0) {
    cout<<"out of memory";
    return 1;
  } else {
    cout<<"we are good"<<endl;
  }
  // input.seekg(8);
  input.read (buffer,size);
  // buffer[size] = '\0';
  // ofstream fout("side.png");
  // fout<<buffer;

  // cout<<"real size is "<<strlen(buffer)<<endl;;
  // fout.close();
  
   cout<<4<<endl;


 
  // char *buffer;
  // FILE* fp = NULL;

  // fp = fopen(argv[1], "r+b");
  // unsigned long size;
  // if (fp != NULL)
  // {
  //   fseek(fp, 0L, SEEK_END);
  //   size = ftell(fp);

  //   fseek(fp, 0L, SEEK_SET);
  //   buffer = new char[size];
  //   cout<<"read size is "<<fread (buffer, 1, size, fp)<<endl;;
  //   fclose(fp);
  // }

  // fp = fopen (argv[2],"w+b");
  // if (fp!=NULL)
  // {
  //   fwrite (buffer,1,size,fp);
  //   fclose (fp);
  // }


  image.set_contents(buffer,size);
  // image.set_contents("lalal11111a\0laaaaa");
  image.set_name(argv[3]);

  {
    // Write the new address book back to disk.
    cout<<5<<endl;
    fstream output(argv[2], ios::out | ios::trunc | ios::binary);
    if (!image.SerializeToOstream(&output)) {
      cerr << "Failed to write address book." << endl;
      return -1;
    }
    cout<<6<<endl;
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}