#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class TransposeMyMusic {
public:
  string transposeMusic(vector <string>, string);
};
 
const string sharp_chords[12] = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
const string flat_chords[12] = { "A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab" };
 
const string flat_keys[12] = { "Bb", "Bbm", "Db", "Dbm", "Eb", "Ebm", "F", "Fm", "Gb", "Gbm", "Ab", "Abm" };
 
string to_flat( string S ) 
{
  string suffix;
  if( S[S.length()-1] == 'm' ) { suffix = "m"; S = S.substr( 0, S.length() - 1 ); }
 
  for( int i = 0; i < 12; ++i )
    if( sharp_chords[i] == S ) return flat_chords[i] + suffix;
  return S + suffix;
}
 
string to_sharp( string S ) 
{
  string suffix;
  if( S[S.length()-1] == 'm' ) { suffix = "m"; S = S.substr( 0, S.length() - 1 ); }
 
  for( int i = 0; i < 12; ++i )
    if( flat_chords[i] == S ) return sharp_chords[i] + suffix;
  return S + suffix;
}
 
int rank( string S )
{
  string suffix;
  if( S[S.length()-1] == 'm' ) { suffix = "m"; S = S.substr( 0, S.length() - 1 ); }
 
  S = to_flat( S );
  
  for( int i = 0; i < 12; ++i )
    if( flat_chords[i] == S ) return i;
  return -1;
}
 
bool is_flat( string S )
{
  for( int i = 0; i < 12; ++i )
    if( flat_keys[i] == S ) return true;
  return false;
}
 
string TransposeMyMusic::transposeMusic(vector <string> sheetMusic, string newKey) {
  string sheet;
  
  for( int i = 0; i < sheetMusic.size(); ++i )
    sheet += sheetMusic[i];
 
  istringstream in( sheet );
  ostringstream out;
 
  string originKey; in >> originKey;
  
  int delta = rank( newKey ) - rank( originKey );
  bool flat = is_flat( newKey );
  
  if( flat ) out << to_flat( newKey );
  else out << to_sharp( newKey );
  
//  cout << delta << endl;
  
  string S;
  
  while( in >> S ) {
    out << " ";
 
    if( S == "|" ) out << "|";
    else {
      string suffix;
      if( S[S.length()-1] == 'm' ) { suffix = "m"; S = S.substr( 0, S.length() - 1 ); }
      
//      cout << "S = " << S << endl;
//      cout << "rank = " << rank( S ) << endl;
      
      int x = ( rank( S ) + delta + 12 ) % 12;
      
      if( flat ) out << flat_chords[x] + suffix;
      else out << sharp_chords[x] + suffix;
    }
  }
  
  return out.str();
}
