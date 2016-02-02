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
	bool operator () ( const Vertex<T> * u, const Vertex<T> * v){
		return u->distance > v->distance;
	}
};


template <class T>
float dijkstra(Graph<T>& g, T src) {
	float cost = 0.0;

	unordered_map<T, Vertex<T> *> vertices = g.vertices;
	map<Edge<T>, float> weight = g.weights;

	priority_queue< Vertex<T> * , vector<Vertex<T> *>, compare<T>> pq;


	//initialize the vertices and add to the priority_queue
	for(auto it = vertices.begin();
	it != vertices.end(); it++){
		it -> second -> visited = false;
		it -> second -> prev = 0;

		if(it->first == src){
			it -> second -> distance = 0;
		}
		else{
			it -> second -> distance = FLT_MAX;
		}

		pq.push(it->second);

	}

	while(!pq.empty()){

		Vertex<T> * pair = pq.top();

		pq.pop();
		T u = pair -> id;

		cout<< "v:" << u << " cost:"<< vertices[u]->distance<< endl;
		//cout<< " pair:"<< pair->distance << endl;

		//update the value of cost
		if(vertices[u]->distance != FLT_MAX){
			cost+= g.get_weight(vertices[u]->prev,u);
		}

		for(auto it = vertices[u]->edges.begin();
		it != vertices[u]->edges.end(); it++){

			T v = vertices[*it]->id;
			float alt = vertices[u]->distance + g.get_weight(u,v);

			//relax the edges for all the vertices
			if(alt < vertices[v]->distance){
				vertices[v]->distance = alt;
				vertices[v]->prev = u;
			}
		}

	}
	// TODO: Problem 1

	return cost;
}

#endif
