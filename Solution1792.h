#pragma once
#include <vector>
#include <queue> // priority_queue is used to store the classes with the highest gain in pass ratio when adding an extra student
#include <tuple> // tuple is used for priority_queue, to store gain, pass, total
using namespace std;
//1792. Maximum Average Pass Ratio
//Solved
//Medium
//There is a school that has classes of students and each class will be having a final exam.
//You are given a 2D integer array classes, where classes[i] = [passi, totali].
//You know beforehand that in the ith class, there are totali total students, 
//but only passi number of students will pass the exam.
//You are also given an integer extraStudents.There are another extraStudents brilliant students 
//that are guaranteed to pass the exam of any class they are assigned to.
//You want to assign each of the extraStudents students to a class in a way
//that maximizes the average pass ratio across all the classes.
//The pass ratio of a class is equal to the number of students of the class 
//that will pass the exam divided by the total number of students of the class.
//The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
//Return the maximum possible average pass ratio after assigning the extraStudents students.
//Answers within 10^-5 of the actual answer will be accepted.
//Example 1:
//Input: classes = [[1, 2], [3, 5], [2, 2]], extraStudents = 2
//Output : 0.78333
//Explanation : You can assign the two extra students to the first class.The average pass ratio will be equal to(3 / 4 + 3 / 5 + 2 / 2) / 3 = 0.78333.
//Example 2 :
//Input: classes = [[2, 4], [3, 9], [4, 5], [2, 10]], extraStudents = 4
//Output : 0.53485
//Constraints :
//    1 <= classes.length <= 10^5
//    classes[i].length == 2
//    1 <= passi <= totali <= 10^5
//    1 <= extraStudents <= 10^5

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto ratio = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
			}; // ratio is the gain in pass ratio when adding an extra student to a clas
        priority_queue<tuple<double, int, int>> order;
        for (auto& c : classes) {
            order.push({ ratio(c[0], c[1]), c[0], c[1] });
		} // push all classes into the priority queue with their gain( call ratio), pass, total.
        while (extraStudents--) {
            auto [r, p, t] = order.top();
            order.pop();
            order.push({ ratio(p + 1, t + 1), p + 1, t + 1 });
		} // for each extra student, pop the class with the highest gain, add the student to it, and push it back to the queue
        double totalRatio = 0.0;
        while (!order.empty()) {
            auto [r, p, t] = order.top();
            order.pop();
            totalRatio += (double)p / t;
		} // calculate the total pass ratio of all classes
		return totalRatio / classes.size(); // return the average pass ratio
    }
};