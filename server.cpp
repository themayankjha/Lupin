#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <vector>

struct coordinate
{
    int x;
    int y;
};

std::vector<coordinate> queue;
void queueval(int , int);
coordinate dequeueval();
void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out);

int main ()
{
  std::cout << "Initializing....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string datain;
		  std::string dataout;
		  std::vector<std::string> out;
		  const char delim = '_';
		  new_sock >> datain;
		  if(datain.rfind("ASK",0)==0)
		  {
			  coordinate cod=dequeueval();
			  dataout=std::to_string(cod.x)+"_"+std::to_string(cod.y);
			  
		  }

		  else if (datain.rfind("PUSH",0)==0)
		  {
				tokenize(datain, delim, out);
				queueval(stoi(out[1]),stoi(out[2]));
        std::cout<<datain;
				dataout="Success";
		  }

      else if (datain.rfind("CHECK",0)==0)
		  {
				if(queue.size()==5){
          dataout="YES";
        }
        else{
          dataout="NO";
        }
		  }
		  

		  new_sock << dataout;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}

void queueval(int xval, int yval){
coordinate point;
point.x=xval;
point.y=yval;
queue.insert(queue.begin(),point);
}

coordinate dequeueval(){
    coordinate point;
    int n = queue.size();
    point = queue[n-1];
    queue.pop_back();
    return point;
}

void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;
 
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}