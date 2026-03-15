#import "lib.typ" : *

// #pagebreak()

// 以下是正文部分(可选)
#show: project.with(
  title: "算法与数据结构",
  author:"Know Spring Rice Bucket"
  )


 
#pagebreak()


#text(
  size: 12pt,       // 本页字体大小
  font: ("New Computer Modern","Source Han Serif SC"),
  
)[
#set outline(depth: 3, indent: auto)
#show outline: set align(center)

#let outline-title(s) = text(size: 20pt, s.clusters().intersperse(h(1em)).join())
#show outline.entry.where(
  level: 1
): it => {
  v(20pt, weak: true)
  strong(it)
}
#show outline.entry.where(
  level: 2
): it => {
  v(16pt, weak: true)
  it
}
#show outline.entry.where(
  level: 3
): it => {
  v(16pt, weak: true)
  it
}
#outline(title: outline-title("目录"))

#pagebreak()
]

#let Ma=$"Ma"$

#let rescnt=counter("reser")
#let res(it)={text[#rescnt.step()
*Result #context rescnt.display():* #it
]
}

= 

#pagebreak()