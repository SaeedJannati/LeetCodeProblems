package Problems;

public class LeetCode1401CircleAndRectangleOverlapping {
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
      double xDiff= xCenter>=x1&&xCenter<=x2?0: Math.min( Math.abs(xCenter-x1),Math.abs(xCenter-x2));
      double yDiff= yCenter>=y1 && yCenter<=y2?0: Math.min( Math.abs(yCenter-y1),Math.abs(yCenter-y2));
      return  xDiff*xDiff+yDiff*yDiff<=radius*radius;
    }
}
