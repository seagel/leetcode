#include <bits/stdc++.h>
using namespace std;

int convertToInt(string no) {
	stringstream ss(no);
	int ans;
	ss >> ans;
	return ans;
}

vector<int> solve(vector<vector<string>> logs) {
	map<string, set<pair<int, int>>> inventory;
	vector<int> ans;
	for (auto log : logs) {
		string key = log[1];
		cout << log[0] << endl;
		int count = convertToInt(log[2]);
		if (log[0] == "supply") {
			int price = convertToInt(log[3]);
			if (inventory.find(key) == inventory.end()) {
				inventory[key] = set<pair<int, int>>();
				inventory[key].insert({price, count});
			} else {
				auto it = inventory[key].lower_bound({price, 1});
				if (it == inventory[key].begin()) {
					inventory[key].insert({price, count});
				} else if (it != inventory[key].end() && it->first == price) {
					auto record = *it;
					inventory[key].erase(it);
					record.second += count;
					inventory[key].insert(record);
				} else {
					it--;
					if (it->first == price) {
						auto record = *it;
						inventory[key].erase(it);
						record.second += count;
						inventory[key].insert(record);
					} else {
						inventory[key].insert({price, count});
					}
				}
			}
		} else if (log[0] == "return") {
			int oldPrice = convertToInt(log[3]);
			int price = convertToInt(log[4]);
			auto it = inventory[key].lower_bound({price, 1});
			if (it == inventory[key].begin()) {
				inventory[key].insert({price, count});
			} else if (it != inventory[key].end() && it->first == price) {
				auto record = *it;
				inventory[key].erase(it);
				record.second += count;
				inventory[key].insert(record);
			} else {
				it--;
				if (it->first == price) {
					auto record = *it;
					inventory[key].erase(it);
					record.second += count;
					inventory[key].insert(record);
				} else {
					inventory[key].insert({price, count});
				}
			}
		} else {
			int revenue = 0;
			while (count > 0) {
				if (count >= inventory[key].begin()->second) {
					revenue += inventory[key].begin()->second *
						inventory[key].begin()->first;
					count = count - inventory[key].begin()->second;
					inventory[key].erase(inventory[key].begin());
				} else {
					revenue += count * inventory[key].begin()->first;
					auto record = *inventory[key].begin();
					inventory[key].erase(inventory[key].begin());
          // cout<<record.first<<" "<<record.second<<endl;
					record.second -= count;
          count = 0;
					inventory[key].insert(record);
				}
			}
			cout << revenue << endl;
			ans.push_back(revenue);
		}
		for (auto entry : inventory) {
			cout << entry.first << endl;
			for (auto item : entry.second) {
				cout << item.first << " " << item.second << endl;
			}
		}
	}
	return ans;
}

int main() {
	vector<vector<string>> logs;
	logs.push_back({"supply", "item1", "2", "100"});
	logs.push_back({"supply", "item2", "3", "60"});
	logs.push_back({"sell", "item1", "1"});
	logs.push_back({"sell", "item1", "1"});
	logs.push_back({"sell", "item2", "2"});
	logs.push_back({"return", "item2", "1", "60", "40"});
	logs.push_back({"sell", "item2", "1"});
	logs.push_back({"supply", "item2", "1","50"});

	solve(logs);

	return 0;
}
