require(graphics)

# string concatenate
sc = function(a, b, s="") {
    paste(a, b, sep="")
}

plotit = function(what, leg=F) {
	x = tabs[[1]]$n
	ys = sapply(tabs, function (t) { t[[what]] })
	#x = head(x, 10)
	#ys = head(ys, 10)

	# 
	if (what == "calls") {
		ys = ys / (x*log(x))
		ylbl = sc(what, " / n ln(n)")
	} else {
		ys = ys / (x*log(x))
		ylbl = sc(what, " / n ln(n)")
	}
	x = log2(x)


	# calculate limits
	xl =c(min(x), max(x))
	ymin = min(apply(ys, 1, min))
	ymax = max(apply(ys, 1, max))
	yl = c(ymin, ymax)

	# plottting
	#par(mgp=c(axis.title.position, axis.label.position, axis.line.position))
	par(mgp=c(1.8, 0.6, 0))
	l=length(tabs)
	colors=rainbow(l, s=1, v=1, start=0, end=max(1, l-1)/l, alpha=1)
	plot(x, xlim=xl, ylim=yl, type="n", xlab="lg(n)", ylab=ylbl, log="")
	for (i in 1:l) {
		y = ys[,i]
		lines(x, y, type="l", col=colors[[i]])
	}
	if (leg)
		legend("topright", algs, col=colors, lty=1)
}

plotlegend = function(x, y) {
	par(xpd=TRUE)
	l=length(tabs)
	colors=rainbow(l, s=1, v=1, start=0, end=max(1, l-1)/l, alpha=1)
	legend("topright",  inset=c(-0.3,0), algs, col=colors, lty=1)
}


#############

args = commandArgs(TRUE)
dir=args[[1]]

#algs = c('Lomuto','LomutoMoves','Hoare','Hoare1','Sedgewick','SedgewickMoves','SedgewickSentinels','Wirth','Sin','SinSentinels','YaroSimple','Yaro','3Pivot0','3Pivot1','3Pivot2','3Pivot3')
#algs = c('Lomuto','Hoare','Hoare1','Sedgewick','Wirth','Sin','Yaro')
#algs = c('Sedgewick', 'Yaro')
#algs = c('Lomuto','Hoare')
#algs = c('Sedgewick','Sin','Yaro')
#algs = c('Lomuto','LomutoMoves','Sedgewick','Sin','Yaro','3Pivot2')

#algs = c('Lomuto','LomutoMoves')
#,'Hoare','Hoare1','Sedgewick','SedgewickMoves','SedgewickSentinels','Wirth','Sin','SinSentinels','YaroSimple','Yaro')
#algs = c('Lomuto','LomutoMoves')

algs = c('Sedgewick','Yaro','3Pivot2')

###############

algs = sc('Quicksort', algs)
tabs = lapply(algs, function (a) { read.csv(sc(sc(dir, a), "-Rand.txt"), header=T, sep="") })

#quartz("Quicksorts", 10, 6)
#par(mfrow=c(1,1), mar=c(4,4,2,2))
#plotit("time", T)
#z <- locator(1)
#q()


quartz("Quicksorts", 10, 6)
#pdf(paste(algs[1], ".pdf", sep=""))
par(mfrow=c(2,2), mar=c(3,3,0.5,0.5))
plotit("cmps")
plotit("moves")
plotit("calls", T)
plotit("time")	
#plotlegend(1000, 0.04)


z <- locator(1)
q()
