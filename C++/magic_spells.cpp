/*You are battling a powerful dark wizard. He casts his spells from a distance, giving you only a few seconds to react and conjure your counterspells. For a counterspell to be effective, you must first identify what kind of spell you are dealing with.

The wizard uses scrolls to conjure his spells, and sometimes he uses some of his generic spells that restore his stamina. In that case, you will be able to extract the name of the scroll from the spell. Then you need to find out how similar this new spell is to the spell formulas written in your spell journal.

Spend some time reviewing the locked code in your editor, and complete the body of the counterspell function.

Check Dynamic cast to get an idea of how to solve this challenge.

Input Format

The wizard will read  scrolls, which are hidden from you.
Every time he casts a spell, it's passed as an argument to your counterspell function.*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell {
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell {
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell {
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
auto *x0 = dynamic_cast<Fireball*>(spell);
  if (x0) { x0->revealFirepower(); return ;}
  auto *x1 = dynamic_cast<Frostbite*>(spell);
  if (x1) {x1->revealFrostpower(); return ;}
  auto *x2 = dynamic_cast<Thunderstorm*>(spell);
  if (x2) {x2->revealThunderpower(); return ; }
  auto *x3 = dynamic_cast<Waterbolt*>(spell);
  if (x3) {x3->revealWaterpower(); return; }
OBOBOBOB
  string a = spell->revealScrollName(), b = SpellJournal::read();
OBOB  int m = a.size(), n = b.size();
  vector<vector<int> > s(m+1, vector<int>(n+1, 0));
OB  for (int i = 0; i < m; i++) {
OBOB    for (int j = 0; j < n; j++)
      s[i+1][j+1] = max(s[i][j]+(a[i]==b[j]), max(s[i+1][j], s[i][j+1]));
  }
  cout << s[m][n] << '\n';
}
OB
class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            }
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
//complete code
