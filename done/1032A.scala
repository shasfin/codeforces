object Solve {
   def main(args: Array[String]) {
      val n_k = readLine().split(' ').map(_.toInt)
      val n = n_k(0)
      val k = n_k(1)
      val utensils : Array[Int] = readLine().split(' ').map(_.toInt)
      
      // organize utensil types into map from type to counts
      val counts = new scala.collection.mutable.HashMap[Int, Int].withDefaultValue(0)
      utensils.foreach(value => counts(value) += 1)

      // find number of utensil sets
      val maxCount = counts.valuesIterator.max
      val nofSets = (((maxCount - 1) / k) + 1) * k
      
      // sum the differences (nof Sets - count) for all utensils
      val sum = counts.valuesIterator.map(value => nofSets - value).sum
      
      println(sum)
   }
}
