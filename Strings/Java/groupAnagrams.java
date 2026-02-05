private static List<List<String>> groupAnagrams(String[] words) {
    Map<String, List<String>> map = new HashMap<>();
    for (String word : words) {
        char[] chars = word.toCharArray();
        Arrays.sort(chars);
        String sortedWord = new String(chars);
        if (!map.containsKey(sortedWord)) {
            map.put(sortedWord, new ArrayList<>());
        }
        map.get(sortedWord).add(word);
    }
    return new ArrayList<>(map.values());
}

public static void main(String[] args) {
    String[] words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    List<List<String>> anagrams =  groupAnagrams(words);
    System.out.println("Anagrams: " + anagrams);
}




