def tarai(x, y, z)
  if x <= y
    return y
  else
    return tarai(tarai(x - 1, y, z),
                 tarai(y - 1, z, x),
                 tarai(z - 1, x, y))
  end
end

n_iter = 10
times = []
n_iter.times do
  start_time = Time.now
  tarai(13, 5, 0)
  end_time = Time.now
  elapsed_time = end_time - start_time
  times << elapsed_time
end

average_time = times.sum / n_iter
variance = times.inject(0.0) { |r, i| r += (i - average_time) ** 2 } / n_iter
std_time = Math.sqrt(variance)

puts "Ruby version: #{RUBY_VERSION}"
puts "Average elapsed_time: #{average_time} sec"
puts "Standard deviation: #{std_time} sec"
