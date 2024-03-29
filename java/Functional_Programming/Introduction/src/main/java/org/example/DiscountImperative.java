package org.example;

import java.math.BigDecimal;
import static  org.example.Prices.prices;

public class DiscountImperative {
  public static void main(String[] args) {
    BigDecimal totalOfDiscountedPrices = BigDecimal.ZERO;

    for(BigDecimal price : prices) {
      if(price.compareTo(BigDecimal.valueOf(20)) > 0)
        totalOfDiscountedPrices =
                totalOfDiscountedPrices.add(price.multiply((BigDecimal.valueOf(0.9))));
    }

    System.out.println("Total of discount prices: " + totalOfDiscountedPrices);
  }
}
