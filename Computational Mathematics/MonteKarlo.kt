package laba7

import Laba4.differentiation
import Laba5.f
import Laba5.methodRectangle
import Laba5.methodSimpson
import Laba5.methodTrap
import java.util.concurrent.ThreadLocalRandom

fun main(args: Array<String>) {
    val a = -1.0
    val b = 1.0
    var n = 10
    var J = 0.0
    var J1 = 0.0
    var correct = 1.0
    val epsilon = 0.001
//    while(Math.abs(correct) > epsilon) {
//        J1 = integralMonteKarlo(::f7, a, b, n)
//        correct = J1 - J
//        J = J1
//        n+=10
//    }
    val res = integralMonteKarlo(::f7, a, b, n)
    println(res)
    val result3 = methodRectangle(::f7, a, b, n)
    println("Метод Симпсона: $result3")
}

fun integralMonteKarlo(func: (Double) -> Double, a: Double, b: Double, n: Int): Double {
    var sum = 0.0
    var sumd = 0.0
    var x: Double
    var y: Double
    var c: Double
    var d: Double

    val h: Double = (b - a) / n

    c = func(a); //max
    d = func(a); // min
    x = a + h
    while (x <= b) {
        if (func(x) > c) c = func(x)
        if (func(x) < d) d = func(x)

        x += h
    }
    for (i in 1 until n) {
        val rand: Double = ThreadLocalRandom.current().nextDouble(0.0, 1.0)
        val rand2: Double = ThreadLocalRandom.current().nextDouble(0.0, 1.0)
        x = rand * (b - a) + a
        y = rand2 * (d - c) + c
        sum += func(x)
    }
    return h * sum
}

fun f7(x: Double): Double {
    return x / (1 + x + x * x)
}