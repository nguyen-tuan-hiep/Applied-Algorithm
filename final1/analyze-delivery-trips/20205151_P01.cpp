#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Trip {
    string code;
    string customerCode;
    string date;
    string time;
    int quantity;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    fflush(stdin);
    freopen("TRAVEL_TIME_TRIP-3-input.txt", "r", stdin);
    vector<string> dates;
    string s;
    while (cin >> s && s != "*") {
        dates.push_back(s);
    }

    vector<Trip> trips;
    while (cin >> s && s != "***") {
        Trip trip;
        trip.code = s;
        cin >> trip.customerCode >> trip.date >> trip.time >> trip.quantity;
        trips.push_back(trip);
    }

    while (cin >> s && s != "***") {
        if (s == "TOTAL_QTY") {
            int totalQty = 0;
            for (Trip trip : trips) {
                totalQty += trip.quantity;
            }
            cout << totalQty << endl;
        } else if (s == "QTY_CUSTOMER") {
            string customer_code;
            cin >> customer_code;

            int totalQty = 0;
            for (Trip trip : trips) {
                if (trip.customerCode == customer_code) {
                    totalQty += trip.quantity;
                }
            }
            cout << totalQty << endl;
        } else if (s == "QTY_MAX_PERIOD") {
            string from_date, from_time, to_date, to_time;
            cin >> from_date >> from_time >> to_date >> to_time;
            int maxQty = 0;

            // add all trips in the period to a vector
            vector<Trip> tripsInPeriod;
            for (Trip trip : trips) {
                if (trip.date >= from_date && trip.date <= to_date) {
                    if (trip.date == from_date && trip.time < from_time) {
                        continue;
                    }
                    if (trip.date == to_date && trip.time > to_time) {
                        continue;
                    }
                    tripsInPeriod.push_back(trip);
                }
            }

            // return the trip with max quantity
            for (Trip trip : tripsInPeriod) {
                if (trip.quantity > maxQty) {
                    maxQty = trip.quantity;
                }
            }
            cout << maxQty << endl;

        } else if (s == "TOTAL_TRIPS") {
            map<string, int> tripCodes;
            for (Trip trip : trips) {
                tripCodes[trip.code]++;
            }
            cout << tripCodes.size() << endl;

        } else if (s == "TRAVEL_TIME_TRIP") {
            string trip_code;
            cin >> trip_code;

            // add the time of the trip to the vector
            vector<int> times;
            for (Trip trip : trips) {
                if (trip.code == trip_code) {
                    long second = stoi(trip.time.substr(6, 2)) + 60 * stoi(trip.time.substr(3, 2)) + 3600 * stoi(trip.time.substr(0, 2));
                    times.push_back(second);
                }
            }

            // create a new vector where each element is the difference between the current element and the previous element
            vector<int> travelTimes;
            for (int i = 0; i < times.size() - 1; i++) {
                travelTimes.push_back(abs(times[i + 1] - times[i]));
            }

            // return the sum of all elements in the vector
            int totalTravelTime = 0;
            for (int travelTime : travelTimes) {
                totalTravelTime += travelTime;
            }
            cout << totalTravelTime << endl;

        } else if (s == "MAX_CONFLICT_TRIP") {
            // compute the subset of trips in which any two trips have overlap working time and the cardinality of the subset is maximal.

            // Return the cardinality of the subset found
        }
    }

    return 0;
}