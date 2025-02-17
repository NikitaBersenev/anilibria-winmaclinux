#ifndef USERCONFIGURATIONVIEWMODEL_H
#define USERCONFIGURATIONVIEWMODEL_H

#include <QObject>

class UserConfigurationViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int opacityPlayerPanel READ opacityPlayerPanel WRITE setOpacityPlayerPanel NOTIFY opacityPlayerPanelChanged)
    Q_PROPERTY(bool notCloseReleaseCardAfterWatch READ notCloseReleaseCardAfterWatch WRITE setNotCloseReleaseCardAfterWatch NOTIFY notCloseReleaseCardAfterWatchChanged)
    Q_PROPERTY(bool usingScrollAcceleration READ usingScrollAcceleration WRITE setUsingScrollAcceleration NOTIFY usingScrollAccelerationChanged)
    Q_PROPERTY(bool hideStatistics READ hideStatistics WRITE setHideStatistics NOTIFY hideStatisticsChanged)

private:
    QString m_cacheFileName { "userconfiguration.cache" };
    QString m_opacityPlayerPanelField { "opacityPlayerPanel" };
    QString m_notCloseReleaseCardAfterWatchField { "notCloseReleaseCardAfterWatch" };
    QString m_usingScrollAccelerationField { "usingScrollAcceleration" };
    QString m_hideStatisticsField { "hideStatisticsField" };
    int m_opacityPlayerPanel { 50 };
    bool m_notCloseReleaseCardAfterWatch { false };
    bool m_usingScrollAcceleration { true };
    bool m_hideStatistics { false };

public:
    explicit UserConfigurationViewModel(QObject *parent = nullptr);

    bool notCloseReleaseCardAfterWatch() const noexcept { return m_notCloseReleaseCardAfterWatch; }
    void setNotCloseReleaseCardAfterWatch(const bool notCloseReleaseCardAfterWatch) noexcept;

    int opacityPlayerPanel() const noexcept { return m_opacityPlayerPanel; }
    void setOpacityPlayerPanel(int opacityPlayerPanel) noexcept;

    bool usingScrollAcceleration() const noexcept { return m_usingScrollAcceleration; }
    void setUsingScrollAcceleration(const bool usingScrollAcceleration) noexcept;

    bool hideStatistics() const noexcept { return m_hideStatistics; };
    void setHideStatistics(const bool hideStatistics) noexcept;

    Q_INVOKABLE void saveSettingsToFile();

private:

    void readSettingsFromFile();

signals:
    void opacityPlayerPanelChanged();
    void notCloseReleaseCardAfterWatchChanged();
    void usingScrollAccelerationChanged();
    void hideStatisticsChanged();

};

#endif // USERCONFIGURATIONVIEWMODEL_H
