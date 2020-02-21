#include <iostream>
#include <sstream>

template<typename T>
struct Node{

    public:
        Node<T> *next;
        int data;

        Node() = default;

        Node(std::initializer_list<T> values){
            if(values.size() == 0){
                throw new std::invalid_argument("List can't be empty");
            }
            this->data = values.begin()[0];
            Node<T> *current = this;
            for(std::size_t value_index = 1; value_index < values.size(); ++value_index){
                current->next = new Node<T>();
                current = current->next;
                current->data = values.begin()[value_index];
            }
        }

        std::string toStr() const{
            std::stringstream ss;
            ss << "["<<*this << "]";
            return ss.str();
        }

        ~Node(){
            if(this->next != nullptr){
                delete this->next;
            }
        }

        friend std::ostream& operator<<(std::ostream &out, const Node &root){
            out << root.data;
            if(root.next != nullptr){
                out << ", " << *root.next;
            }
            return out;
        }
};

// template<typename U>
// std::ostream& operator<<(std::ostream &out, const Node<U> &root){
//     out << root.data;
//     if(root.next != nullptr){
//         out << ", " << *root.next;
//     }
//     return out;
// }

template<typename T>
uint kthLast(Node<T> const *node, uint index, T &retval){
    if(node == nullptr){
        return 0;
    }
    const uint my_index = kthLast(node->next, index, retval) + 1;

    if(my_index == index){
        retval = node->data;
    }

    return my_index;
}


Node<int> *partition(Node<int> *root, int value){
    Node<int> *current = root;
    while(current->next != nullptr){
        if(current->next->data < value){
            Node<int> *next = current->next;
            current->next = next->next;
            next->next = root;
            root = next;
        } else {
            current = current->next;
        }
    }
    return root;
}

int main(void){
    Node<int> root{1,2,3,7,8,5,3,2,4,5,6};
    int retval;
    Node<int> *newRoot = partition(&root, 5);
    std::cout << newRoot->toStr() << std::endl;
}
