#include <iostream>

using namespace std;

class Player{
	public:
		virtual void play()=0;//pure virtual function
		virtual float getScore()=0;//pure virtual function
};
class Cricketer : public Player{
	public:
		float getScore(){	return 100;	}
};
class TestPlayer : public Cricketer{
	public:
		void play(){	cout << "Play very slow\n";	}
};
int main(){
	Cricketer c;
	//TestPlayer tp;
	cout << "Score:" << tp.getScore() << '\n';
	tp.play();
	return 0;
}