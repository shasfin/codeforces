object Solution {
    def main(args: Array[String]) {
        val n_k = readLine().split(' ').map(_.toInt)
        val n = n_k(0)
        val k = n_k(1)
        val tabs = readLine().split(' ').map(_.toInt)
      
        val totalSum = tabs.sum
      
        val partialSums = new Array[Int](k)
        tabs.zipWithIndex.foreach {case (tab, index) =>
          partialSums(index % k) -= tab
        }
        val differences = partialSums.map{sum => Math.abs(sum+totalSum)}
        val result = differences.max
      
       println(result)
    }
}
