// tangent lines from point q to the circle
int tangent_lines_from_point(PT p, double r, PT q, line &u, line &v){
	int x = sign(dist2(p, q) - r * r);
	if (x < 0) return 0; // point in cricle
	if (x == 0){ // point on circle
		u = line(q, q + rotateccw90(q - p));
		v = u;
		return 1;
	}

	double d = dist(p, q);
	double l = r * r / d;
	double h = sqrt(r * r - l * l);
	u = line(q, p + ((q - p).truncate(l) + (rotateccw90(q - p).truncate(h))));
	v = line(q, p + ((q - p).truncate(l) + (rotatecw90(q - p).truncate(h))));
	return 2;
}
// returns outer tangents line of two circles
// if inner == 1 it returns inner tangent lines
int tangents_lines_from_circle(PT c1, double r1, PT c2, double r2, bool inner, line &u, line &v){
	if(inner) r2 = -r2;
	PT d = c2 - c1;
	double dr = r1 - r2, d2 = d.norm2(), h2 = d2 - dr * dr;
	if(d2 == 0 || h2 < 0){
		assert(h2 != 0);
		return 0;
	}
	vector<pair<PT, PT>>out;
	for (int tmp: {- 1, 1}){
		PT v = (d * dr + rotateccw90(d) * sqrt(h2) * tmp) / d2;
		out.push_back({c1 + v * r1, c2 + v * r2});
	}
	u = line(out[0].first, out[0].second);
	if(out.size() == 2) v = line(out[1].first, out[1].second);
	return 1 + (h2 > 0);
}
// returns two circle c1, c2 which is tangent to line u,  goes through
// point q and has radius r1; 0 for no circle, 1 if c1 = c2 , 2 if c1 != c2
int get_circle(line u, PT q, double r1, circle &c1, circle &c2){
	double d = dist_from_point_to_line(u.a, u.b, q);
	if (sign(d - r1 * 2.0) > 0) return 0;
	if (sign(d) == 0) {
		cout << u.v.x << ' ' << u.v.y << '\n';
		c1.p = q + rotateccw90(u.v).truncate(r1);
		c2.p = q + rotatecw90(u.v).truncate(r1);
		c1.r = c2.r = r1;
		return 2;
	}
	line u1 = line(u.a + rotateccw90(u.v).truncate(r1), u.b + rotateccw90(u.v).truncate(r1));
	line u2 = line(u.a + rotatecw90(u.v).truncate(r1), u.b + rotatecw90(u.v).truncate(r1));
	circle cc = circle(q, r1);
	PT p1, p2; vector<PT> v;
	v = circle_line_intersection(q, r1, u1.a, u1.b);
	if(!v.size()) v = circle_line_intersection(q, r1, u2.a, u2.b);
	v.push_back(v[0]);
	p1 = v[0], p2 = v[1];
	c1 = circle(p1, r1);
	if(p1 == p2){
		c2 = c1;
		return 1;
	}
	c2 = circle(p2, r1);
	return 2;
}
