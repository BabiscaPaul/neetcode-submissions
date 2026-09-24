#include <iterator>
#include <list>
#include <string> 
using std::string;

class BrowserHistory {
public:
    BrowserHistory(string homepage) : history {homepage} , current{history.begin()} { }
    
    void visit(string url) {
        history.erase(std::next(current), history.end());
        history.push_back(url);
        ++current;
    }
    
    string back(int steps) {
        while (steps > 0 && current != history.begin()) {
            --steps;
            --current;
        }
        return *current;
    }
    
    string forward(int steps) {
    
        while (steps > 0 && std::next(current) != history.end()) {
            --steps;
            ++current;
        }

        return *current;
    }

private:
    std::list<string> history;
    std::list<string>::iterator current;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */