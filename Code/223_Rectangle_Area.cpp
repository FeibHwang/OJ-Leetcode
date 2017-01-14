/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

/*
instead of checking whether overlap, calculate the boundary of the overlap
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //int left = max(A,E), right = max(left,min(C,G));
        //int bottom = max(B,F), top = max(min(D,H),bottom);
        return (C-A)*(D-B) - (max(max(A,E),min(C,G))-max(A,E))*(max(min(D,H),max(B,F))-max(B,F)) + (G-E)*(H-F);
        
    }
};