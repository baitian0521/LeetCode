//
// Created by baitian0521 on 2018/6/21.
//



#pragma once

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    vector<int> getInDegree(vector<vector<int>> &edges, int value) {
        vector<int> back;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][1] == value) {
                back.push_back(i);
            }
        }
        return back;
    }

    int *int_array = NULL;
    int vertex = 0;

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        vertex = edges.size() + 2;
        int_array = new int[vertex];
        vector<int> back_value;
        if (edges.size() > 3) {
            set<int> set1;
            for (auto b : edges) {
                set1.insert(b[1]);
            }
            vector<int> temp_vertex_vector;
            for (auto &c : set1) {
                vector<int> temp = getInDegree(edges, c);
                if (temp.size() == 2) {
                    temp_vertex_vector.swap(temp);
                    break;
                }
            }
            if (temp_vertex_vector.size() == 2) {
                for (int i = temp_vertex_vector.size() - 1; i >= 0; i--) {
                    vector<vector<int>> temp_vvv = edges;
                    auto tttt = temp_vvv.begin() + temp_vertex_vector[i];
                    back_value = *tttt;
                    temp_vvv.erase(tttt);
                    if (!union_find(temp_vvv).empty()) {
                        continue;
                    } else {
                        delete[] int_array;
                        int_array = NULL;
                        return back_value;;
                    }
                }
            }
        }
        back_value = union_find(edges);
        delete[] int_array;
        int_array = NULL;
        return back_value;
    }

    vector<int> union_find(vector<vector<int>> &edges) {
        memset(int_array, 0, vertex * sizeof(int));
        int_array[edges[0][0]] = edges[0][1];
        for (auto item = edges.begin() + 1; item != edges.end(); item++) {
            int start = findVertex(int_array, item->operator[](0));
            int end = findVertex(int_array, item->operator[](1));
            if (start == end) {
                return *item;
            } else {
                int_array[start] = end;
            }
        }
        return vector<int>();

    }

    int findVertex(int int_array[], int value) {
        while (int_array[value] != 0) {
            value = int_array[value];
        }
        return value;
    }

    static void test3_solution() {
        vector<vector<int>> edges;
        edges.push_back(vector<int>{1, 2});
        edges.push_back(vector<int>{1, 3});
        edges.push_back(vector<int>{2, 3});
        Solution temp;
        vector<int> back = temp.findRedundantDirectedConnection(edges);
        cout << back[0] << " | " << back[1] << endl;
    }

    static void test1_solution() {
        vector<vector<int>> edges;
        edges.push_back(vector<int>{2, 1});
        edges.push_back(vector<int>{3, 1});
        edges.push_back(vector<int>{4, 2});
        edges.push_back(vector<int>{1, 4});
        Solution temp;
        vector<int> back = temp.findRedundantDirectedConnection(edges);
        cout << back[0] << " | " << back[1] << endl;
    }

    static void test2_solution() {
        vector<vector<int>> edges;
        edges.push_back(vector<int>{75, 25});
        edges.push_back(vector<int>{58, 64});
        edges.push_back(vector<int>{20, 56});
        edges.push_back(vector<int>{29, 11});
        edges.push_back(vector<int>{99, 78});
        edges.push_back(vector<int>{60, 28});
        edges.push_back(vector<int>{73, 55});
        edges.push_back(vector<int>{44, 92});
        edges.push_back(vector<int>{51, 75});
        edges.push_back(vector<int>{16, 80});
        edges.push_back(vector<int>{74, 97});
        edges.push_back(vector<int>{64, 8});
        edges.push_back(vector<int>{4, 53});
        edges.push_back(vector<int>{79, 59});
        edges.push_back(vector<int>{33, 49});
        edges.push_back(vector<int>{39, 5});
        edges.push_back(vector<int>{28, 87});
        edges.push_back(vector<int>{27, 71});
        edges.push_back(vector<int>{94, 62});
        edges.push_back(vector<int>{46, 98});
        edges.push_back(vector<int>{91, 20});
        edges.push_back(vector<int>{49, 91});
        edges.push_back(vector<int>{92, 60});
        edges.push_back(vector<int>{10, 3});
        edges.push_back(vector<int>{48, 51});
        edges.push_back(vector<int>{22, 37});
        edges.push_back(vector<int>{3, 100});
        edges.push_back(vector<int>{21, 17});
        edges.push_back(vector<int>{30, 79});
        edges.push_back(vector<int>{31, 68});
        edges.push_back(vector<int>{19, 24});
        edges.push_back(vector<int>{2, 61});
        edges.push_back(vector<int>{32, 77});
        edges.push_back(vector<int>{100, 30});
        edges.push_back(vector<int>{72, 15});
        edges.push_back(vector<int>{84, 41});
        edges.push_back(vector<int>{14, 47});
        edges.push_back(vector<int>{6, 94});
        edges.push_back(vector<int>{68, 42});
        edges.push_back(vector<int>{47, 31});
        edges.push_back(vector<int>{86, 43});
        edges.push_back(vector<int>{18, 73});
        edges.push_back(vector<int>{37, 63});
        edges.push_back(vector<int>{1, 34});
        edges.push_back(vector<int>{95, 6});
        edges.push_back(vector<int>{12, 27});
        edges.push_back(vector<int>{40, 13});
        edges.push_back(vector<int>{52, 86});
        edges.push_back(vector<int>{69, 38});
        edges.push_back(vector<int>{82, 2});
        edges.push_back(vector<int>{81, 54});
        edges.push_back(vector<int>{13, 19});
        edges.push_back(vector<int>{23, 97});
        edges.push_back(vector<int>{96, 84});
        edges.push_back(vector<int>{9, 50});
        edges.push_back(vector<int>{87, 14});
        edges.push_back(vector<int>{59, 33});
        edges.push_back(vector<int>{42, 35});
        edges.push_back(vector<int>{90, 4});
        edges.push_back(vector<int>{50, 90});
        edges.push_back(vector<int>{65, 18});
        edges.push_back(vector<int>{83, 70});
        edges.push_back(vector<int>{78, 45});
        edges.push_back(vector<int>{35, 57});
        edges.push_back(vector<int>{38, 83});
        edges.push_back(vector<int>{5, 16});
        edges.push_back(vector<int>{36, 26});
        edges.push_back(vector<int>{97, 12});
        edges.push_back(vector<int>{89, 40});
        edges.push_back(vector<int>{77, 76});
        edges.push_back(vector<int>{88, 69});
        edges.push_back(vector<int>{17, 32});
        edges.push_back(vector<int>{25, 96});
        edges.push_back(vector<int>{15, 67});
        edges.push_back(vector<int>{53, 10});
        edges.push_back(vector<int>{11, 39});
        edges.push_back(vector<int>{62, 46});
        edges.push_back(vector<int>{70, 1});
        edges.push_back(vector<int>{26, 22});
        edges.push_back(vector<int>{71, 89});
        edges.push_back(vector<int>{7, 95});
        edges.push_back(vector<int>{67, 74});
        edges.push_back(vector<int>{57, 7});
        edges.push_back(vector<int>{41, 99});
        edges.push_back(vector<int>{45, 44});
        edges.push_back(vector<int>{61, 36});
        edges.push_back(vector<int>{98, 85});
        edges.push_back(vector<int>{54, 66});
        edges.push_back(vector<int>{76, 48});
        edges.push_back(vector<int>{8, 82});
        edges.push_back(vector<int>{56, 52});
        edges.push_back(vector<int>{63, 65});
        edges.push_back(vector<int>{55, 29});
        edges.push_back(vector<int>{66, 93});
        edges.push_back(vector<int>{43, 72});
        edges.push_back(vector<int>{85, 88});
        edges.push_back(vector<int>{93, 21});
        edges.push_back(vector<int>{34, 58});
        edges.push_back(vector<int>{24, 81});
        edges.push_back(vector<int>{80, 9});
        Solution temp;
        vector<int> back = temp.findRedundantDirectedConnection(edges);
        cout << back[0] << " | " << back[1] << endl;
    }
};




















