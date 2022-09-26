#include <bits/stdc++.h>
using namespace std;
map<vector<int>, struct node *> mp;
set<vector<int>> S;
typedef long long element_type;
typedef struct node *NODE_PTR;
// declaring prototypes of the function
void dfs_call_scissor(NODE_PTR traverse_node, element_type n, vector<int> v, char f_stat, element_type flag);
void dfs_call_rock(NODE_PTR traverse_node, element_type n, vector<int> v, char f_state, element_type flag);
void dfs_call_paper(NODE_PTR traverse_node, element_type n, vector<int> v, char f_state, element_type flag);
void if_rock(NODE_PTR curr_node, element_type N, vector<int> ind);
void if_scissor(NODE_PTR curr_node, element_type N, vector<int> ind);
void if_paper(NODE_PTR curr_node, element_type N, vector<int> ind);
char which_state(vector<int> vecu);
// output vector  that stores the pointer to all nodes of output dfa.
vector<NODE_PTR> output_vector;
element_type number = 1;
// input is taken in the form vector of structs of the type character rock paper scissor
struct input
{
    char c;
    element_type rock;
    element_type paper;
    element_type scissor;
};
// every node would have its value along with if its visited or not 
struct node
{
    char c;
    element_type id;
    element_type is_visited;
    NODE_PTR r;
    NODE_PTR p;
    NODE_PTR s;
};
// thats the main dfacall for each node 
void right_dfs(NODE_PTR node, element_type N, vector<int> vecu)
{
    if_paper(node, N, vecu);
    if_scissor(node, N, vecu);
    if_rock(node, N, vecu);
}
// make node function that allocates memory to node and its unique id 
NODE_PTR make_node(char value, element_type id)
{
    NODE_PTR new_node = (NODE_PTR)malloc(sizeof(struct node));
    // new_node->opponent = opponent
    new_node->id = id;
    new_node->c = value;
    new_node->r = NULL;
    new_node->s = NULL;
    new_node->p = NULL;
    new_node->is_visited = 0;
    return new_node;
}
// thats the vector of structure for taking input 
vector<struct input> vec;
// each time i choose the state which is reverse of maximum state that occured
char which_state(vector<int> vecu)
{
    element_type count_r = 0;
    element_type count_p = 0;
    element_type count_s = 0;
    char st;
    for (element_type i = 0; i < vecu.size(); i++)
    {
        if (vec[vecu[i]].c == 'R')
        {
            count_r++;
        }
        else if (vec[vecu[i]].c == 'S')
        {
            count_s++;
        }
        else if (vec[vecu[i]].c == 'P')
        {
            count_p++;
        }
    }
    if (count_p >= count_s)
    {
        if (count_p >= count_r)
        {
            st = 'S';
        }
        else
        {
            st = 'P';
        }
    }
    else
    {
        if (count_s >= count_r)
            st = 'R';
        else
            st = 'P';
    }
    return st;
}
// in case the opponent plays rock on my current state and assigns it the set as well as determine which state will i play 
// state i play is just the reverse of what comes 
void if_rock(NODE_PTR curr_node, element_type N, vector<int> ind)
{
    element_type flag = 0;
    vector<int> global_hu_mai;
    vector<int> veco;
    for (element_type i = 0; i < N; i++)
    {
        element_type check = -1;
        if (vec[i].c == 'R')
        {
            if (find(ind.begin(), ind.end(), i + 1) == ind.end())
            {

                continue;
            }
            else
            {
                flag = 1;

                if (curr_node->c == 'R')
                {
                    veco.push_back(vec[i].rock - 1);
                    check = 0;
                }
                else if (curr_node->c == 'P')
                {
                    veco.push_back(vec[i].paper - 1);
                    check = 1;
                }
                else if (curr_node->c == 'S')
                {
                    veco.push_back(vec[i].scissor - 1);
                    check = 2;
                }
            }
            if (check != -1)
            {
                if (check == 0)
                {
                    global_hu_mai.push_back(vec[i].rock);
                }
                else if (check == 1)
                {
                    global_hu_mai.push_back(vec[i].paper);
                }
                else if (check == 2)
                {
                    global_hu_mai.push_back(vec[i].scissor);
                }
            }
        }
    }

    char f_state = which_state(veco);
    dfs_call_rock(curr_node, N, global_hu_mai, f_state, flag);
}
// in case the opponent plays paper on my current state and assigns it the set as well as determine which state will i play 
// state i play is just the reverse of what comes 
void if_paper(NODE_PTR curr_node, element_type N, vector<int> ind)
{
    element_type flag = 0;
    vector<int> global_hu_mai;
    vector<int> veco;
    for (element_type i = 0; i < N; i++)
    {
        element_type check = -1;
        if (vec[i].c == 'P')
        {
            if (find(ind.begin(), ind.end(), i + 1) == ind.end())
            {

                continue;
            }
            else
            {
                flag = 1;

                if (curr_node->c == 'R')
                {
                    veco.push_back(vec[i].rock - 1);
                    check = 0;
                }
                else if (curr_node->c == 'P')
                {
                    veco.push_back(vec[i].paper - 1);
                    check = 1;
                }
                else if (curr_node->c == 'S')
                {
                    veco.push_back(vec[i].scissor - 1);
                    check = 2;
                }
            }
            if (check != -1)
            {
                if (check == 0)
                {
                    global_hu_mai.push_back(vec[i].rock);
                }
                else if (check == 1)
                {
                    global_hu_mai.push_back(vec[i].paper);
                }
                else if (check == 2)
                {
                    global_hu_mai.push_back(vec[i].scissor);
                }
            }
        }
    }

    char f_state = which_state(veco);
    dfs_call_paper(curr_node, N, global_hu_mai, f_state, flag);
}
// in case the opponent plays scissor on my current state and assigns it the set as well as determine which state will i play 
// state i play is just the reverse of what comes 
void if_scissor(NODE_PTR curr_node, element_type N, vector<int> ind)
{

    vector<int> global_hu_mai;
    element_type flag = 0;
    vector<int> veco;
    for (element_type i = 0; i < N; i++)
    {
        element_type check = -1;
        if (vec[i].c == 'S')
        {
            if (find(ind.begin(), ind.end(), i + 1) == ind.end())
            {

                continue;
            }
            else
            {
                flag = 1;

                if (curr_node->c == 'R')
                {
                    veco.push_back(vec[i].rock - 1);
                    check = 0;
                }
                else if (curr_node->c == 'P')
                {
                    veco.push_back(vec[i].paper - 1);
                    check = 1;
                }
                else if (curr_node->c == 'S')
                {
                    veco.push_back(vec[i].scissor - 1);
                    check = 2;
                }
            }
            if (check != -1)
            {
                if (check == 0)
                {
                    global_hu_mai.push_back(vec[i].rock);
                }
                else if (check == 1)
                {
                    global_hu_mai.push_back(vec[i].paper);
                }
                else if (check == 2)
                {
                    global_hu_mai.push_back(vec[i].scissor);
                }
            }
        }
    }

    char f_state = which_state(veco);
    dfs_call_scissor(curr_node, N, global_hu_mai, f_state, flag);
}
// here if opponent plays rock then this function is called to make new node or map back to existing node 
void dfs_call_rock(NODE_PTR traverse_node, element_type n, vector<int> v, char f_state, element_type flag)
{

    char is_rock = f_state;
    if (flag == 0)
    {
        traverse_node->r = NULL;
    }
    else
    {
        sort(v.begin(), v.end());
        if (S.find(v) == S.end())
        {

            S.insert(v);
            number++;
            NODE_PTR new_node = (NODE_PTR)malloc(sizeof(struct node));
            new_node->c = is_rock;
            new_node->id = number;
            mp[v] = new_node;
            output_vector.push_back(new_node);
            traverse_node->r = new_node;
            right_dfs(new_node, n, v);
        }
        else
        {
            traverse_node->r = mp[v];
        }
    }
}
// here if opponent plays paper then this function is called to make new node or map back to existing node 
void dfs_call_paper(NODE_PTR traverse_node, element_type n, vector<int> v, char f_state, element_type flag)
{

    char is_paper = f_state;
    if (flag == 0)
    {
        traverse_node->p = NULL;
    }
    else
    {
        sort(v.begin(), v.end());
        if (S.find(v) == S.end())
        {

            S.insert(v);
            number++;
            NODE_PTR new_node = (NODE_PTR)malloc(sizeof(struct node));
            new_node->c = is_paper;
            new_node->id = number;
            mp[v] = new_node;
            traverse_node->p = new_node;
            output_vector.push_back(new_node);
            right_dfs(new_node, n, v);
        }
        else
        {
            traverse_node->p = mp[v];
        }
    }
}
// here if opponent plays scissor then this function is called to make new node or map back to existing node 
void dfs_call_scissor(NODE_PTR traverse_node, element_type n, vector<int> v, char f_state, element_type flag)
{

    char is_scissor = f_state;
    if (flag == 0)
    {
        traverse_node->s = NULL;
    }
    else
    {
        sort(v.begin(), v.end());
        if (S.find(v) == S.end())
        {

            S.insert(v);
            number++;
            NODE_PTR new_node = (NODE_PTR)malloc(sizeof(struct node));
            new_node->c = is_scissor;
            new_node->id = number;
            mp[v] = new_node;
            traverse_node->s = new_node;
            output_vector.push_back(new_node);
            right_dfs(new_node, n, v);
        }
        else
        {
            traverse_node->s = mp[v];
        }
    }
}
// tyrna print dfa via dfs :p but gives repeated state in case already visited
void print_dfs(NODE_PTR nd)
{
    std::cout << nd->c << " ";

    if (nd->r != NULL)
    {
        std::cout << nd->r->id << " ";
    }
    else
    {
        std::cout << nd->id << " ";
    }
    if (nd->p != NULL)
    {
        std::cout << nd->p->id << " ";
    }
    else
    {
        std::cout << nd->id << " ";
    }
    if (nd->s != NULL)
    {
        std::cout << nd->s->id << " ";
    }
    else
    {
        std::cout << nd->id << " ";
    }
    std::cout << "\n";
    nd->is_visited = 1;
    if (nd->r != NULL)
    {
        if (!(nd->r)->is_visited)
            print_dfs(nd->r);
    }
    if (nd->s != NULL)
    {
        if (!(nd->s)->is_visited)
            print_dfs(nd->s);
    }
    if (nd->p != NULL)
    {
        if (!(nd->p)->is_visited)
            print_dfs(nd->p);
    }
}
// printing of final dfa via using vector
void print_finaldfa(element_type number_states)
{
    for (element_type i = 0; i < number_states; i++)
    {
        cout << output_vector[i]->c << " ";
        if (output_vector[i]->r == NULL)
        {
            cout << output_vector[i]->id << " ";
        }
        else
        {
            cout << output_vector[i]->r->id << " ";
        }
        if (output_vector[i]->p == NULL)
        {
            cout << output_vector[i]->id << " ";
        }
        else
        {
            cout << output_vector[i]->p->id << " ";
        }
        if (output_vector[i]->s == NULL)
        {
            cout << output_vector[i]->id << " ";
        }
        else
        {
            cout << output_vector[i]->s->id << " ";
        }
        cout << "\n";
    }
}
int main()
{
    element_type n;
    cin >> n;
    element_type count_r = 0;
    element_type count_p = 0;
    element_type count_s = 0;
    char intial;

    for (element_type i = 0; i < n; i++)
    {
        struct input temp;
        cin >> temp.c >> temp.rock >> temp.paper >> temp.scissor;

        if (temp.c == 'R')
        {
            count_r++;
        }
        else if (temp.c == 'S')
        {
            count_s++;
        }
        else if (temp.c == 'P')
        {
            count_p++;
        }

        vec.push_back(temp);
    }
    if (count_p >= count_s)
    {
        if (count_p >= count_r)
        {
            intial = 'S';
        }
        else
        {
            intial = 'P';
        }
    }
    else
    {
        if (count_s >= count_r)
        {
            intial = 'R';
        }
        else
        {
            intial = 'P';
        }
    }
    NODE_PTR element_type_state;
    element_type_state = (NODE_PTR)malloc(sizeof(struct node));
    element_type_state->c = intial;
    element_type_state->id = 1;
    element_type_state->p = NULL;
    element_type_state->r = NULL;
    element_type_state->s = NULL;
    vector<int> v;
    for (element_type i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    mp[v] = element_type_state;
    output_vector.push_back(element_type_state);
    right_dfs(element_type_state, n, v);
    std::cout << number << "\n";
    //   print_dfs(element_type_state);
    print_finaldfa(number);

    return 0;
}
