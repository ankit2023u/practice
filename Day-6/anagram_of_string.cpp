// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string s1, string s2) {
    // Create a frequency array to count occurrences of each character (a-z)
    vector<int> count(26, 0);
    
    // Count frequency of characters in the first string
    for(int i = 0; i < (int)s1.size(); i++){
        count[s1[i] - 'a']++;
    }
    
    int removals = 0;
    
    // For each character in the second string
    // If it's available in count (from s1), decrease its count
    // Otherwise, it must be removed (increase removals)
    for(int i = 0; i < (int)s2.size(); i++){
        if(count[s2[i] - 'a']){
            count[s2[i] - 'a']--;
        }
        else{
            removals++;
        }
    }
    
    // Add remaining characters from s1 that were not matched
    for(int i = 0; i < 26; i++){
        if(count[i]){
            removals += count[i];
            count[i] = 0;
        }
    }
    
    // Return total removals needed to make both strings anagrams
    return removals;
}
