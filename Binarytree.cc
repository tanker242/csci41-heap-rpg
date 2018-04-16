                              
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <term.h>
using namespace std;

struct Event{
    //bool is_output = 1;

    string question;

    vector<string> lines;

    Event (string N, vector<string> vec): question(N), lines(vec){}

};


struct Node {
    Event data;
    vector<Node*> paths;
Node(): data("",{}),paths({}){}

    Node(string question, vector<string> lines1, bool onepath = false)
    : data(question,lines1)

    {

    if (onepath)
        paths = vector <Node*> (1, new Node());
    else paths = vector <Node*> (lines1.size(), new Node());

    }
    };


class Tree {
    Node *current;
    Node *head= NULL;
    void delete(node* N) {
        for (node* temp : N-> paths)
            delete(temp);
        delete N; }


    void ClearScreen()
    {
        if (!cur_term)
        {
            int result;
                                               
setupterm( NULL, STDOUT_FILENO, &result );
            if (result <= 0) return;
        }

        putp( tigetstr( "clear" ) );
    }


    public:
    Tree(){};
    ~Tree(){
        delete(head);
    }

    void initdialogue() {
        cout << current->data.question << endl;
        cout << "Please choose from these responses." << endl;
        for (int i =0; i < current->data.lines.size();i++)
            cout << i << ": " << current-> data.lines.at(i) << endl;
        cout << endl;
        int input =0;
        cin >> input;
        if (input < 0 || input >= current->data.lines.size()) exit(1);
        if (current->paths.size() != current->data.lines.size()) {

            if (current->paths.size() != 1) exit(1);
            current = current->paths.front();

            return;



        }

        current = current->paths.at(input);
    }

    void insert(Node *temp, char data1){
        if (! head) {
            Node *temp1 = new Node(data1);
            head = temp1;
            return;
        }
        else if (data1 == temp->data)
            return;
        else if (data1 < temp->data){
            if (temp->left == NULL){
                Node *temp1 = new Node(data1);
temp-> left = temp1;
                return;
            }
            insert(temp->left,data1);
        }
        else if (data1 > temp -> data) {
            if (temp -> right == NULL) {
                Node *temp1 = new Node(data1);
                temp -> right = temp1;
                return;
            }
            insert(temp -> right,data1);
        }
    }

};

