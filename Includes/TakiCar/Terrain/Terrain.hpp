// Copyright (c) 2020 Justin Kim

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef TAKICAR_TERRAIN_HPP
#define TAKICAR_TERRAIN_HPP

#include <vector>

namespace TakiCar
{
class Terrain
{
public:
    Terrain(double width, double height, double maxAltitude, double minAltitude,
            double resolution);

    void Generate(size_t epochs);

private:
    std::vector<std::vector<double>> m_map;

    double m_width;
    double m_height;
    double m_maxAltitude;
    double m_minAltitude;
    double m_resolution;

    int m_cellSizeWidth;
    int m_cellSizeHeight;
};
} // namespace TakiCar

#endif
