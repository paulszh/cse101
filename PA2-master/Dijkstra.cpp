// CSE 101 Winter 2016, PA 2
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: February 5th, 2016 at 11:59 PM

#ifndef __DIJKSTRA_CPP__
#define __DIJKSTRA_CPP__

#include "Graph.hpp"
#include <queue>
#include <vector>
#include <cfloat>
using namespace std;
// include more libraries as needed

template <class T>
struct compare
{
	//dist[v]
	bool operator () ( const pair<T,float> u, const pair<T,float> v){
		return u.second < v.second;
	}
};


template <class T>
float dijkstra(Graph<T>& g, T src) {
    float cost = 0.0;

    unordered_map<T, Vertex<T> *> vertices = g.vertices;
    map<Edge<T>, float> weight = g.weights;

    priority_queue< pair<T,float> , vector<pair<T,float>>, compare<T> > pq;


    for(auto it = vertices.begin();
        it != vertices.end(); it++){
    	it -> second -> visited = false;
    	it -> second -> distance = FLT_MAX;
    	it -> second -> prev = 0;

    	pair<T,float> v(it->first, it->second->distance);
    	pq.push(v);
    }

    vertices[src]->distance = 0;

    while(!pq.empty()){

    	pair<T,float> pair = pq.top();
    	pq.pop();

    	Vertex<T> u = pair.first;

    	for(auto it = u.edges.begin(); 
	    it != u.edges.end(); it++){

    		Vertex<T> v = vertices[*it]->id;
    		float alt = u.distance + g.get_weight(u.id, v.id);

    		if(alt < v.distance){
    			vertices[*it]->id = alt;
    			vertices[*it]->prev = u.id;
    		}
	    }

    }

    // TODO: Problem 1

    return cost;
}

#endif