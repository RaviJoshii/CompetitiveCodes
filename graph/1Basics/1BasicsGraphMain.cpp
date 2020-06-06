#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<stack>

using namespace std;

class Edge {
    public: 
        int nbr;
        int wt;
};
vector<vector<Edge>> graph;
vector<vector<Edge>> dag;

void addEdgeDirected(int v1, int v2, int wt)
{
    Edge e1;
    e1.nbr = v2;
    e1.wt = wt;
    dag[v1].push_back(e1);
}

void addEdge(int v1, int v2, int wt)
{
    Edge e1;
    e1.nbr = v2;
    e1.wt = wt;
    graph[v1].push_back(e1);

    Edge e2;
    e2.nbr = v1;
    e2.wt = wt;
    graph[v2].push_back(e2);
}

void addEdge(vector<vector<Edge>>& g, int v1, int v2, int wt)
{
    Edge e1;
    e1.nbr = v2;
    e1.wt = wt;
    g[v1].push_back(e1);

    Edge e2;
    e2.nbr = v1;
    e2.wt = wt;
    g[v2].push_back(e2);
}

void display()
{
    for(int v = 0; v < graph.size(); v++)
    {
        cout << v << " -> ";
        for(int n = 0; n < graph[v].size(); n++)
        {
            Edge ne = graph[v][n];
            cout << "[" << ne.nbr << "-" << ne.wt << "], ";
        }
        cout << "." << endl;
    }
}

void display(vector<vector<Edge>>& g)
{
    for(int v = 0; v < g.size(); v++)
    {
        cout << v << " -> ";
        for(int n = 0; n < g[v].size(); n++)
        {
            Edge ne = g[v][n];
            cout << "[" << ne.nbr << "-" << ne.wt << "], ";
        }
        cout << "." << endl;
    }
}

bool haspath(int s, int d, vector<bool>& visited)
{
    if(s == d)
    {
        return true;
    }

    visited[s] = true;
    for(int n = 0; n < graph[s].size(); n++)
    {
        Edge ne = graph[s][n];
        if(visited[ne.nbr] == false)
        {
            bool hpfntod = haspath(ne.nbr, d, visited);
            if(hpfntod == true)
            {
                return true;
            }
        }
    }

    return false;
}

int sd = INT_MAX;
string sdp;
int ld = INT_MIN;
string ldp;
int cd = INT_MAX; // qualified min
string cdp;
int fd = INT_MIN; // qualified max
string fdp;

void printallpaths(int s, int d, vector<bool>& visited,
                   string psf, int dsf, int factor)
{
    if(s == d)
    {
        psf = psf + to_string(d);
        cout << psf << "@" << dsf << endl;
        if(dsf < sd){
            sd = dsf;
            sdp = psf;
        }

        if(dsf > ld){
            ld = dsf;
            ldp = psf;
        }

        if(dsf > factor && dsf < cd)
        {
            cd = dsf;
            cdp = psf;
        }

        if(dsf < factor && dsf > fd)
        {
            fd = dsf;
            fdp = psf;
        }

        return;
    }
    visited[s] = true;
    for(int n = 0; n < graph[s].size(); n++)
    {
        Edge ne = graph[s][n];
        if(visited[ne.nbr] == false)
        {
            printallpaths(ne.nbr, d, visited, 
                          psf + to_string(s), 
                          dsf + ne.wt, factor);
        }
    }
    visited[s] = false;
}

void hamiltonianPnC(int s, vector<bool>& visited, 
                    int csf, string psf, int os)
{
    if(csf == graph.size() - 1)
    {
        psf += to_string(s);
        cout << psf;

        for(int n = 0; n < graph[s].size(); n++)
        {
            Edge ne = graph[s][n];
            if(ne.nbr == os)
            {
                cout << "*" << endl;
                return;
            }
        }

        cout << "." << endl;
        return;
    }

    visited[s] = true;
    for(int n = 0; n < graph[s].size(); n++)
    {
        Edge ne = graph[s][n];
        if(visited[ne.nbr] == false)
        {
            hamiltonianPnC(ne.nbr, visited, 
                           csf + 1, 
                           psf + to_string(s), os);
        }
    }
    visited[s] = false;
}

bool bfs(int s, int d){
    vector<bool> visited (graph.size(), false);
    queue<int> q;

    q.push(s);
    while(q.size() > 0){
        // grmpa
        int rem = q.front();
        q.pop();

        if(visited[rem] == true){
            continue;
        }
        visited[rem] = true;
        
        if(rem == d){
            return true;
        }

        for(int n = 0; n < graph[rem].size(); n++){
            Edge ne = graph[rem][n];
            if(visited[ne.nbr] == false){
                q.push(ne.nbr);
            }
        }
    }

    return false;
}

string gscc(int r, vector<bool>& visited){
    string comp = "";

    queue<int> q;
    q.push(r);
    while(q.size() > 0){
        int rem = q.front();
        q.pop();

        if(visited[rem] == true){
            continue;
        }
        visited[rem] = true;

        comp += to_string(rem);

        for(int n = 0; n < graph[rem].size(); n++)
        {
            Edge ne = graph[rem][n];
            if(visited[ne.nbr] == false)
            {
                q.push(ne.nbr);
            }
        }
    }

    return comp;
}

vector<string> gcc(){
    vector<string> comps;
    vector<bool> visited(graph.size(), false);

    for(int v = 0; v < graph.size(); v++){
        if(visited[v] == false)
        {
            string comp = gscc(v, visited);
            comps.push_back(comp);
        }
    }

    return comps;
}

bool isConnected(){
    int counter = 0;
    vector<bool> visited(graph.size(), false);

    for(int v = 0; v < graph.size(); v++){
        if(visited[v] == false)
        {
            gscc(v, visited);
            counter++;
            
            if(counter == 2)
            {
                return false;
            }
        }
    }

    return true;
}

bool isCompCyclic(int r, vector<bool>& visited)
{
    queue<int> q;
    q.push(r);

    while(q.size() > 0)
    {
        int rem = q.front();
        q.pop();

        if(visited[rem] == true)
        {
            return true;
        }
        visited[rem] = true;

        for(int n = 0; n < graph[rem].size(); n++)
        {
            Edge ne = graph[rem][n];
            if(visited[ne.nbr] == false)
            {
                q.push(ne.nbr);
            }
        }
    }

    return false;
}

bool isCyclic()
{
    vector<bool> visited(graph.size(), false);

    for(int v = 0; v < graph.size(); v++)
    {
        if(visited[v] == false)
        {
            bool isCyclic = isCompCyclic(v, visited);
            if(isCyclic == true)
            {
                return true;
            }
        }
    }

    return false;
}

class BiPair 
{
    public:
        int v;
        int l;
};

bool isCompBipartite(int r, vector<int>& visited)
{
    queue<BiPair> q;
    BiPair bp;
    bp.v = r;
    bp.l = 1;
    q.push(bp);

    while(q.size() > 0)
    {
        BiPair rem = q.front();
        q.pop();

        if(visited[rem.v] != 0)
        {
            int ol = visited[rem.v];
            int nl = rem.l;

            if(ol % 2 != nl % 2)
            {
                return false;
            }
        }
        visited[rem.v] = rem.l;

        for(int n = 0; n < graph[rem.v].size(); n++)
        {
            Edge ne = graph[rem.v][n];
            if(visited[ne.nbr] == 0)
            {
                BiPair np;
                np.l = rem.l + 1;
                np.v = ne.nbr;
                q.push(np);
            }
        }
    }

    return true;
}

bool isBipartite()
{
    vector<int> visited(graph.size(), 0);

    for(int v = 0; v < graph.size(); v++)
    {
        if(visited[v] == 0)
        {
            bool isBip = isCompBipartite(v, visited);
            if(isBip == false)
            {
                return false;
            }
        }
    }

    return true;
}

class DPair 
{
    public:
        int v;
        int c;
        string p;

        DPair(int v, int c, string p)
        {
            this->v = v;
            this->c = c;
            this->p = p;
        }

        bool operator<(const DPair& other) const 
        {
            return this->c < other.c;
        }

        bool operator>(const DPair& other) const 
        {
            return this->c > other.c;
        }
};

void djikstra(int s)
{
    priority_queue<DPair, vector<DPair>, greater<DPair>> pq;
    DPair rtp(s, 0, to_string(s));
    pq.push(rtp);

    vector<bool> visited (graph.size(), false);

    while(pq.size() > 0)
    {
        DPair rem = pq.top();
        pq.pop();

        if(visited[rem.v] == true)
        {
            continue;
        }
        visited[rem.v] = true;

        cout << rem.v << "@" << rem.c << " via " << rem.p << endl;
        for(int n = 0; n < graph[rem.v].size(); n++)
        {
            Edge ne = graph[rem.v][n];
            if(visited[ne.nbr] == false)
            {
                DPair np(ne.nbr, rem.c + ne.wt, 
                         rem.p + to_string(ne.nbr));
                pq.push(np);
            }
        }
    }
}

class PPair 
{
    public:
        int v;
        int av;
        int c;

        PPair(int v, int av, int c)
        {
            this->v = v;
            this->av = av;
            this->c = c;
        }

        bool operator>(const PPair& other) const
        {
            return this->c > other.c;
        }
};

void prims()
{
    vector<vector<Edge>> mst (graph.size(), vector<Edge>());
    vector<bool> visited (graph.size(), false);

    priority_queue<PPair, vector<PPair>, greater<PPair>> pq;
    PPair rp (0, -1, 0);
    pq.push(rp);
    
    while(pq.size() > 0)
    {
        PPair rem = pq.top();
        pq.pop();

        if(visited[rem.v] == true)
        {
            continue;
        }
        visited[rem.v] = true;

        if(rem.av != -1)
        {
            addEdge(mst, rem.v, rem.av, rem.c);
        }

        for(int n = 0; n < graph[rem.v].size(); n++)
        {
            Edge ne = graph[rem.v][n];
            if(visited[ne.nbr] == false)
            {
                PPair np(ne.nbr, rem.v, ne.wt);
                pq.push(np);
            }
        }
    }

    display(mst);
}

void topologicalComp(vector<bool>& visited, stack<int>& st, int v)
{
    visited[v] = true;
    for(int n = 0; n < dag[v].size(); n++)
    {
        Edge ne = dag[v][n];
        if(visited[ne.nbr] == false)
        {
            topologicalComp(visited, st, ne.nbr);
        }
    }
    st.push(v);
}

void topological()
{
    stack<int> st;
    vector<bool> visited (dag.size(), false);

    for(int v = 0; v < visited.size(); v++)
    {
        if(visited[v] == false)
        {
            topologicalComp(visited, st, v);
        }
    }

    while(st.size() > 0)
    {
        int v = st.top();
        st.pop();
        cout << v << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    dag.push_back(vector<Edge>());
    dag.push_back(vector<Edge>());
    dag.push_back(vector<Edge>());
    dag.push_back(vector<Edge>());
    dag.push_back(vector<Edge>());
    dag.push_back(vector<Edge>());
    dag.push_back(vector<Edge>());

    addEdgeDirected(0, 1, 1);
    addEdgeDirected(1, 2, 1);
    addEdgeDirected(2, 3, 1);
    addEdgeDirected(0, 4, 1);
    addEdgeDirected(4, 3, 1);
    addEdgeDirected(5, 4, 1);
    addEdgeDirected(5, 6, 1);
    addEdgeDirected(6, 3, 1);
    topological();
    // graph.push_back(vector<Edge>()); // 0
    // graph.push_back(vector<Edge>()); // 1
    // graph.push_back(vector<Edge>()); // 2
    // graph.push_back(vector<Edge>()); // 3
    // graph.push_back(vector<Edge>()); // 4
    // graph.push_back(vector<Edge>()); // 5
    // graph.push_back(vector<Edge>()); // 6

    // addEdge(0, 1, 20);
    // addEdge(1, 2, 10);
    // addEdge(2, 3, 20);
    // addEdge(0, 3, 40);
    // addEdge(3, 4, 2);
    // addEdge(4, 5, 3);
    // addEdge(5, 6, 3);
    // addEdge(4, 6, 8);
    // djikstra(0)
    // prims();

    // cout << isBipartite() << endl;
    // vector<string> comps = gcc();
    // for(int i = 0; i < comps.size(); i++)
    // {
    //     cout << comps[i] << endl;
    // }

    // int n = 10;
    // vector<int> v1 {9, 5, 2, 3, 6, 1};
    // vector<int> v2 {4, 3, 0, 7, 8, 4};

    // for(int v = 0; v < n; v++)
    // {
    //     graph.push_back(vector<Edge>());
    // }
    // for(int e = 0; e < v1.size(); e++)
    // {
    //     addEdge(v1[e], v2[e], 1);
    // }
    // int teams = 0;
    // vector<string> nations = gcc();
    // for(int n1 = 0; n1 < nations.size(); n1++)
    // {
    //     for(int n2 = n1 + 1; n2 < nations.size(); n2++)
    //     {
    //         teams += nations[n1].size() * nations[n2].size();
    //     }
    // }
    // cout << teams << endl;



    // addEdge(2, 5, 5);

    // display();
    // vector<bool> visited (7, false);
    // cout << bfs(0, 6) << endl;
    // hamiltonianPnC(3, visited, 0, "", 3);
    // cout << haspath(0, 6, visited) << endl;
    // printallpaths(0, 6, visited, "", 0, 45);
    // cout << "Smallest Path : " << sdp << "@" << sd << endl;
    // cout << "Largest Path : " << ldp << "@" << ld << endl;
    // cout << "Ceil Path : " << cdp << "@" << cd << endl;
    // cout << "Floor Path : " << fdp << "@" << fd << endl;
}

// class Point {
//     public:
//         int x;
//         int y;
// };

// class Rectangle {
//     public:
//         Point tl;
//         Point br;

//         int area()
//         {
//             int width = abs(tl.x - br.x);
//             int height = abs(tl.y - br.y);
//             return width * height;
//         }
// };

// Point p1;
// p1.x = 10;
// p1.y = 20;

// Point p2;
// p2.x = 30;
// p2.y = 40;

// Rectangle r;
// r.tl = p1;
// r.br = p2;
// cout << r.area() << endl;

