class FoodRatings {
private:
    unordered_map<string,set<pair<int,string>>> store; // stores cuisine -> {-rating, food}
    unordered_map<string, string> foodToCuisine; // stores food -> cuisine
    unordered_map<string, int> foodToRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i =0; i< ratings.size(); i++){
            string cuisine = cuisines[i];
            string food = foods[i];
            int rating = ratings[i];  

            store[cuisine].insert({-rating, food});
            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
        }
    }
    
    void changeRating(string food, int newRating) {
        
        string cuisine = foodToCuisine[food];

        int oldRating = foodToRating[food];
        //remove the old rating from store
        store[cuisine].erase({-oldRating, food});
        store[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    
        return;
    }
    
    string highestRated(string cuisine) {
        return store[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */