

public static void main() {
   LruCache lruCache = new LruCache(4);
   lruCache.put("abc", 1);
   lruCache.put("def", 2);
   lruCache.put("ghi", 3);
   lruCache.put("jkl", 4);
   lruCache.put("mno", 5);
   lruCache.put("pqr", 6);
   lruCache.printAll();
   System.out.println(lruCache.get("abc"));
   System.out.println(lruCache.get("jkl"));
   lruCache.printAll();

   // Thread Safe
   LruCacheThreadSafe lruCacheThreadSafe = new LruCacheThreadSafe(4);
   lruCacheThreadSafe.put("abc", 1);
   lruCacheThreadSafe.put("def", 2);
   lruCacheThreadSafe.put("ghi", 3);
   lruCacheThreadSafe.put("jkl", 4);
   lruCacheThreadSafe.put("mno", 5);
   lruCacheThreadSafe.put("pqr", 6);
   lruCache.printAll();
   System.out.println(lruCacheThreadSafe.get("abc"));
   System.out.println(lruCacheThreadSafe.get("jkl"));
   lruCache.printAll();
}
