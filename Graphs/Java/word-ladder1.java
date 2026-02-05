public static class Pair{
    String word;
    int distance;
    public Pair(String word, int distance){
        this.word = word;
        this.distance = distance;
    }
}

private static int reachTargetWord(List<String> wordList, String startWord, String targetWord) {
    Set<String> wordSet = new HashSet<>(wordList);

    // If target isn't in the list, it's often unreachable depending on rules
    if (!wordSet.contains(targetWord)) return 0;

    Queue<Pair> queue = new LinkedList<>();
    queue.offer(new Pair(startWord,1));
    wordSet.remove(startWord); // mark visited

    while (!queue.isEmpty()){
        Pair pair = queue.poll();
        String currentWord = pair.word;
        int d = pair.distance;

        if (currentWord.equals(targetWord)) {
            return d;
        }
        // Convert to char array for precise index manipulation
        char[] chars = currentWord.toCharArray();
        for(int i = 0; i < currentWord.length(); i++){
            char original = chars[i];
            for(char ch='a'; ch<='z'; ch++){
                if(ch==original){ continue; }
                chars[i] = ch;
                String newWord = new String(chars);

                if(wordSet.contains(newWord)){
                    wordSet.remove(newWord);
                    queue.offer(new Pair(newWord,d+1));
                }
            }
            chars[i] = original;
        }
    }
    return 0;
}

public static void main(String[] args) {
    
    List<String> wordList = List.of("des", "der", "dfr", "dgt", "dfs");
    String startWord = "der";
    String targetWord = "dfs";

    int minimumDistanceToReachTargetWord = reachTargetWord(wordList, startWord, targetWord);
    System.out.println("Minimum Distance: " + minimumDistanceToReachTargetWord);
}

