package Laba5

import java.util.*
//val scanner = Scanner(System.`in`)
//epsilon = scanner.nextDouble()

fun main(args: Array<String>) {
    val a = -1.0
    val b = -0.5
    val epsilon: Double
    var n = 1

    println("Введите требуемую точность: ")
    epsilon = readLine()!!.toDouble();

    var prev: Double
    var curr: Double
    curr = methodTrap(::f, a, b, n)
    var iter = 0
    do {
        prev = curr
        curr = methodTrap(::f, a, b, 2 * n)
        n *= 2
        iter++
    } while (Math.abs(prev - curr) > epsilon)

    println(curr)
    println("Кол-во итераций: $iter")
}

fun methodTrap(func:(Double) -> Double, a: Double, b: Double, n: Int): Double {
    val h: Double = (b - a) / n
    var sum = 0.0
    var x1: Double
    var x2: Double
    for (i in 0 until n) {
        x1 = a + h * i
        x2 = a + h * (i + 1)
        sum += (func(x1) + func(x2)) * h / 2
    }
    return sum
}

fun f(x: Double): Double {
    return Math.pow(Math.cos(x), 3.0) / Math.sqrt(Math.pow(Math.sin(x), 2.0))
}
