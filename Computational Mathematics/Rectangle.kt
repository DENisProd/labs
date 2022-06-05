package Laba5

fun main(args: Array<String>) {
    val a = -1.0
    val b = -0.5
    var n = 1

    println("Введите требуемую точность: ")
    val epsilon: Double = readLine()!!.toDouble();

    var prev: Double
    var curr: Double = methodRectangle(::f,a, b, n)
    var iter = 0
    do {
        prev = curr
        curr = methodRectangle(::f, a, b, 2 * n)
        n *= 2
        iter++
    } while (Math.abs(prev - curr) > epsilon)

    println(curr)
    println("Кол-во итераций: $iter")
}

fun methodRectangle(func:(Double) -> Double, a: Double, b: Double, n: Int): Double {
    var sum = 0.0
    val h = (b - a) / n
    var x: Double
    for (i in 0 until n) {
        x = a + i * h
        sum += h * func(x + h / 2)
    }
    return sum
}