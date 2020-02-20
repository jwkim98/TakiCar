// Copyright (c) 2020 Justin Kim

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <TakiCar/Terrain/Terrain.hpp>
#include <cmath>
#include <random>
#define M_PI 3.14159265358979323846

namespace TakiCar
{
Terrain::Terrain(double width, double height, double maxAltitude,
                 double minAltitude, double resolution)
    : m_width(width),
      m_height(height),
      m_maxAltitude(maxAltitude),
      m_minAltitude(minAltitude),
      m_resolution(resolution)
{
    m_cellSizeWidth = static_cast<int>(width / resolution);
    m_cellSizeHeight = static_cast<int>(height / resolution);
    m_map = std::vector<std::vector<double>>(
        m_cellSizeWidth, std::vector<double>(m_cellSizeHeight));
}

void Terrain::Generate(size_t epochs)
{
    std::random_device device;
    std::mt19937_64 gen(device());

    std::uniform_int_distribution<int> uniformWidth(0, m_cellSizeWidth);
    std::uniform_int_distribution<int> uniformHeight(0, m_cellSizeHeight);
    std::uniform_real_distribution<double> uniformAngle(0.0, 2 * M_PI);

    for (size_t count = 0; count < epochs; ++count)
    {
        auto posX = uniformWidth(gen);
        auto posY = uniformHeight(gen);
        auto angle = uniformAngle(gen);
        auto function = [posX, posY, angle](int x, int y)
        {
            return (x - posX) * tan(angle) - (y - posY);
        };

        for (int x_idx = 0; x_idx < m_cellSizeWidth; ++x_idx)
        {
            for (int y_idx = 0; y_idx < m_cellSizeHeight; ++y_idx)
            {
                if (function(x_idx, y_idx) > 0 && m_map.at(x_idx).at(y_idx) <
                    m_maxAltitude)
                {
                    m_map.at(x_idx).at(y_idx) += 1;
                }
                else if (m_map.at(x_idx).at(y_idx) > m_minAltitude)
                {
                    m_map.at(x_idx).at(y_idx) -= 1;
                }
            }
        }
    }
}
} // namespace TakiCar
