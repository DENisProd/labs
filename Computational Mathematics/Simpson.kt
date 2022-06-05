package Laba5

fun main(args: Array<String>) {
    val a = -1.0
    val b = -0.5
    val epsilon: Double
    var n = 1

    println("Введите требуемую точность: ")
    epsilon = readLine()!!.toDouble();

    var prev: Double
    var curr: Double
    curr = methodSimpson(::f, a, b, n)
    var iter = 0
    do {
        prev = curr
        curr = methodSimpson(::f, a, b, n)
        n *= 2
        iter++
    } while (Math.abs(prev - curr) > epsilon)

    println(curr)
    println("Кол-во итераций: $iter")
}

fun methodSimpson(func:(Double) -> Double, a: Double, b: Double, n: Int): Double {
    var sum: Double = func(a) + func(b)
    val h = (b - a) / n
    var x: Double
    for (j in 1 until 2 * n) {
        x = a + h * 0.5 * j
        sum += if (j % 2 != 0) 4 * func(x) else 2 * func(x)
    }
    return sum * h / 6
}