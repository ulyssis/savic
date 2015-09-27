#include "puMode.h"

#ifndef MORE_AHCHOR_6
class VCoord{
public :
          double W,X,Y,Z;
          VCoord (double w, double x, double y, double z):W(w),X(x),Y(y),Z(z){ }
          VCoord(){}
          bool operator==(const VCoord & other) const
                  {
                          return (other.W-W)<0.001 && (other.X-X)<0.001 && (other.Y-Y)<0.001 && (other.Z-Z)<0.001 ;
                    }
          bool XYZequal (const VCoord & other){

              bool xequal=(other.X-X)<0.0001;
              bool yequal=(other.Y-Y)<0.0001;
              bool zequal=(other.Z-Z)<0.0001;
              return xequal&&yequal&&zequal;

              return other.X==X && other.Y==Y && other.Z==Z ;

          }
          std::ostream& operator<<(std::ostream& os)
          {
              os << W << '/' << X << '/' <<Y<<'/'<<Z;
              return os;
          }

 };
#endif


#ifdef MORE_AHCHOR_6
class VCoord{
public :
          double W,X,Y,Z,X1, X2;
          VCoord (double w, double x, double y, double z, double x1, double x2):W(w),X(x),Y(y),Z(z), X1(x1), X2(x2){ }
          VCoord(){}
          bool operator==(const VCoord & other) const
                  {
                          return (other.W-W)<0.001 && (other.X-X)<0.001 && (other.Y-Y)<0.001 && (other.Z-Z)<0.001 && (other.X1-X1)<0.001 && (other.X2-X2)<0.001;
                    }
          bool XYZequal (const VCoord & other){

              bool wequal=(other.W-W)<0.001;
              bool xequal=(other.X-X)<0.001;
              bool yequal=(other.Y-Y)<0.001;
              bool zequal=(other.Z-Z)<0.001;
              bool x1equal=(other.X1-X1)<0.001;
              bool x2equal=(other.X2-X2)<0.001;

              return wequal&&xequal&&yequal&&zequal&&x1equal&&x2equal;

//              return other.X==X && other.Y==Y && other.Z==Z ;

          }
          std::ostream& operator<<(std::ostream& os)
          {
              os << W << '/' << X << '/' <<Y<<'/'<<Z <<'/'<< X1 << '/'<< X2;
              return os;
          }

 };
#endif
