
class Position{
public :
          double X,Y;
          Position (double x, double y){X=x;Y=y;}
          Position(){}
          bool operator==( Position & other)
                  {
                          return abs(other.X-X)<0.0001 && abs(other.Y-Y)<0.0001 ;
                    }
          bool operator!=( Position & other)
                            {
                                    return abs(other.X-X)>0.0001 || abs(other.Y-Y)>0.0001 ;
                              }


 };
